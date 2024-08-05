/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:47:31 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:55:17 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr;
	unsigned int	i;

	if (!s || !f)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	ptr = str;
	i = 0;
	while (*s)
	{
		*ptr = f(i, *s);
		ptr++;
		s++;
		i++;
	}
	*ptr = '\0';
	return (str);
}

/*
int main()
{
	char *s = "1234567890";
	printf("%s\n", ft_strmapi(s, &ft_toupper));
}
*/