/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:51:50 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/03 10:51:57 by sezequie         ###   ########.fr       */
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

void			error_output(int error);
void			free_list(char **list);
char			*pathfinder(char **envp, char *command);
void			pipex(char **av, char **envp);
void			cmd_one(char **envp, char **argv, int *pipefd);
void			cmd_two(char **envp, char **argv, int *pipefd);
char			*path_builder(char *s1, char *s2, char *s3);

#endif