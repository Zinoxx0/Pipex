/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:51:07 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:51:07 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = 0;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			last = (char *)str;
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (last);
}

/*
int main()
{
	char str[] = "1234567890";
	printf("%s\n", ft_strrchr(str, '0'));
	printf("%s\n", strrchr(str, '0'));
}
*/