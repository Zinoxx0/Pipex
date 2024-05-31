/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:17:32 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:52:46 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	splitcount(const char *check, char c)
{
	int	bo;
	int	l;
	int	k;

	bo = 0;
	l = 0;
	k = 0;
	while (check && check[k] != '\0')
	{
		if (bo == 0 && check[k] != c)
		{
			bo = 1;
			l++;
		}
		else if (check[k] == c)
			bo = 0;
		k++;
	}
	return (l);
}

char	**ft_split(char const *s, char c)
{
	int		o;
	size_t	i;
	size_t	p;
	char	**splitted;

	o = -1;
	i = 0;
	p = 0;
	splitted = (char **)malloc(sizeof(char *) * (splitcount(s, c) + 1));
	if (!splitted || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && o < 0)
			o = i;
		else if ((s[i] == c || i == ft_strlen(s)) && o >= 0)
		{
			splitted[p++] = ft_substr(s, o, i - o);
			o = -1;
		}
		i++;
	}
	splitted[p] = NULL;
	return (splitted);
}

/*
int main()
{
	char str[] = "1234567890";
	char **str2 = ft_split(str, '5');
	printf("%s\n", str2[0]);
	printf("%s\n", str2[1]);
	printf("%s\n", str2[2]);
	printf("%s\n", str2[3]);
	printf("%s\n", str2[4]);
	printf("%s\n", str2[5]);
}
*/