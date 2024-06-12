/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:09:32 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/12 09:19:46 by sezequie         ###   ########.fr       */
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
// Ex: ./pipex file1 cmd1 cmd2 file2
