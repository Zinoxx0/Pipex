/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 06:58:43 by sezequie          #+#    #+#             */
/*   Updated: 2024/08/05 12:31:47 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_opener(int num_pipes, int pipes[][2])
{
	int i = 0;
	if (num_pipes <= 0)
	{
		error_output(0);
		return;
	}

	while (i < num_pipes)
	{
		if (pipe(pipes[i]) < 0)
		{
			error_output(1);
			return;
		}
		i++;
	}
}

void pipe_closer(int pipes[][2], int num_pipes)
{
	int i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void first_child(char **argv, int pipe[])
{
	int infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_output(3);
	dup2(infile, STDIN_FILENO);
	close(pipe[0]);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
}

void last_child(char **argv, int pipe[], int argc)
{
	int outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_output(4);
	dup2(outfile, STDOUT_FILENO);
	close(pipe[1]);
	close(pipe[0]);
}

void middle_child(int in_pipe[], int out_pipe[])
{
	dup2(in_pipe[0], STDIN_FILENO);
	close(in_pipe[0]);
	close(in_pipe[1]);

	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[0]);
	close(out_pipe[1]);
}

void multi_pipe(char **argv, char **envp, int argc)
{
	int i = 0;
	int num_pipes = argc - 5;
	int pipes[num_pipes][2];

	pipe_opener(num_pipes, pipes);
	while (++i <= num_pipes)
	{
		int forkid = fork();

		if (forkid < 0)
		{
			error_output(2);
			return;
		}

		if (forkid == 0)
		{
			if (i == 1)
				first_child(argv, pipes[0]);
			else if (i == num_pipes)
				last_child(argv, pipes[num_pipes - 1], argc);
			else
				middle_child(pipes[i - 2], pipes[i - 1]);
			pipe_closer(pipes, num_pipes);
			char *command = pathfinder(envp, argv[1 + i]);
			char **argv_split = ft_split(argv[1 + i], ' ');
			execve(command, argv_split, envp);
			free_list(argv_split);
			free(command);
			exit(1);
		}
		else
			wait(NULL);
	}
	pipe_closer(pipes, num_pipes);
}

int main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		multi_pipe(argv, envp, argc);
	else
		error_output(0);
	return (0);
}

// Ex: ./pipex file1 cmd1 cmd2 cmd3 file2
