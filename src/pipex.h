/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:51:50 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/03 09:56:24 by sezequie         ###   ########.fr       */
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

void			errorhandling(int error);
void			free_list(char **list);
char			*pathfinder(char **envp, char *command);
void			pipex(char **av, char **envp);
void			firstcommand(char **envp, char **av, int *pipefd);
void			secondcommand(char **envp, char **av, int *pipefd);

#endif