/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:27:27 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/03 10:22:21 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(char **envp, char *command)
{
	int		i;
	char	**paths;
	char	*str;

	if (!command || !access(command, F_OK))
		return (command);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		str = triple_strjoin(paths[i++], "/", command);
		if (!access(str, F_OK))
			break ;
		free(str);
		str = NULL;
	}
	if (!str)
		error_output(5);
	free_list(paths);
	return (str);
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
