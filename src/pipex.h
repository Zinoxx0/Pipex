/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:51:50 by sezequie          #+#    #+#             */
/*   Updated: 2024/05/31 14:54:47 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../Libft/Printf/ft_printf.h"

char	*path_find(char *cmd, char **evnp);
void	execute(char *av, char **envp);
void	ft_error(char *msg);
void	main_process(char **av, char **envp, int *fd);
void	fork_process(char **av, char **envp, int *fd);

#endif