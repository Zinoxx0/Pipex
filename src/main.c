/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:09:32 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/03 10:24:14 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv, envp);
	else
		error_output(0);
	return (0);
}

void	pipex(char **argv, char **envp)
{
	int	forkid;
	int	pipefd[2];

	if (pipe(pipefd))
		error_output(1);
	forkid = fork();
	if (forkid < 0)
		error_output(2);
	if (!forkid)
		cmd_one(envp, argv, pipefd);
	wait(0);
	forkid = fork();
	if (forkid < 0)
		error_output(2);
	if (!forkid)
		cmd_two(envp, argv, pipefd);
	close(pipefd[1]);
	close(pipefd[0]);
	wait(0);
}

void	cmd_one(char **envp, char **argv, int *pipefd)
{
	int		infile;
	char	**argvsplit;
	char	*str;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_output(3);
	if (dup2(infile, STDIN_FILENO) < 0)
		error_output(6);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		error_output(6);
	argvsplit = ft_split(argv[2], ' ');
	str = pathfinder(envp, argvsplit[0]);
	execve(str, argvsplit, envp);
	free_list(argvsplit);
	free(str);
	exit(4);
}

void	cmd_two(char **envp, char **argv, int *pipefd)
{
	int		outfile;
	char	**argvsplit;
	char	*str;

	close(pipefd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_output(4);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		error_output(6);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		error_output(6);
	argvsplit = ft_split(argv[3], ' ');
	str = pathfinder(envp, argvsplit[0]);
	execve(str, argvsplit, envp);
	free_list(argvsplit);
	free(str);
	exit(4);
}
// Ex: ./pipex file1 cmd1 cmd2 file2
