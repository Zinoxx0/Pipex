/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:27:15 by sezequie          #+#    #+#             */
/*   Updated: 2024/06/03 10:18:24 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **list)
{
	int	i;

	if (list)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
	}
}

void	error_output(int error)
{
	if (error == 0)
		perror("Invalid number of parametres");
	if (error == 1)
		perror("Error initializing the pipe");
	if (error == 2)
		perror("Error initializing the fork");
	if (error == 3)
		perror("Error reading infile");
	if (error == 4)
		perror("Error initializing outfile");
	if (error == 5)
		perror("No path found");
	if (error == 6)
		perror("Error related to dup2");
	exit(1);
}
