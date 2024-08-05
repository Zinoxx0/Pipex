/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:37 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:37 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	chr;

	ptr = (unsigned char *)str;
	chr = (unsigned char)c;
	while (len--)
	{
		if (*ptr == chr)
			return (ptr);
		ptr++;
	}
	return (0);
}

/*
int main()
{
	char str[] = "1234567890";
	printf("%s\n", ft_memchr(str, '5', 5));
	printf("%s\n", memchr(str, '5', 5));
}
*/