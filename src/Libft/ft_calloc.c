/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:20 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:20 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n * size);
	return (ptr);
}

/*
int	main()
{
	size_t	num_elements = 5;
	size_t	element_size = sizeof(int);

	// Allocate and initialize memory for an array of 5 integers
	int *arr = (int *)ft_calloc(num_elements, element_size);
	// Check if memory allocation was successful
	if (arr != NULL)
	{
		// Access and modify the elements of the array
		for (size_t i = 0; i < num_elements; i++)
			arr[i] = i + 1;
		// Print the elements of the array
		for (size_t i = 0; i < num_elements; i++)
			printf("%d ", arr[i]);
		// Free the allocated memory when done
		free(arr);
	}
	else
		printf("Memory allocation failed\n");
	return 0;
}
*/