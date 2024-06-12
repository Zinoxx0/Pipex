/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 06:52:53 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/12 08:07:15 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "pipex.h"

void			multi_pipe(char **argv, char **envp);
void			pipe_opener(int num_pipes, int pipes[][2]);
void			pipe_closer(int pipes[][2], int num_pipes);

#endif