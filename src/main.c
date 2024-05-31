/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:09:32 by sezequie          #+#    #+#             */
/*   Updated: 2024/05/31 15:27:00 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	id;
	int		i;

	i = 0;
	if (ac == 5 && check_args(av) == 0)
	{
		if (pipe(fd) == -1)
			ft_error("Error creating pipe\n");
		id = fork();
		if (id == -1)
			ft_error("Error creating fork\n");
		if (id == 0)
			fork_process(av, envp, fd);
		main_process(av, envp, fd);
		while (++i > 3)
			waitpid(-1, NULL, 0);
	}
	else
		ft_printf("Error in arguments\n");
}
