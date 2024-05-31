/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:49 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:49 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c && *str != '\0')
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

/*
int main()
{
	char str[] = "1234567890";
	printf("%s\n", ft_strchr(str, '5'));
	printf("%s\n", strchr(str, '5'));
}
*/