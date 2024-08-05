/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:07:05 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:50:22 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void	*))
{
	t_list	*ptrlst;

	ptrlst = lst;
	while (ptrlst)
	{
		f(ptrlst->content);
		ptrlst = ptrlst->next;
	}
}
