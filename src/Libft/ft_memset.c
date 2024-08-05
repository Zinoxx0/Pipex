/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:46 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:46 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (size > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		size--;
	}
	return (str);
}

/*
int main()
{
	char str[] = "1234567890";
	printf("%s\n", ft_memset(str, 'a', 5));
	printf("%s\n", memset(str, 'a', 5));
}
*/