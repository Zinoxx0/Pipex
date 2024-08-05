/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:14 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:14 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		sign;
	long	res;

	n = 0;
	sign = 1;
	res = 0;
	while (str[n] == ' ' || str[n] == '\t' || str[n] == '\n'
		|| str[n] == '\v' || str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign = -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		res = res * 10 + str[n] - '0';
		n++;
	}
	return (res * sign);
}

/*
int main()
{
	char str[] = "  -1234567890";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/