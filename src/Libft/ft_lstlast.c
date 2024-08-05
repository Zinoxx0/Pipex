/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:01:58 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:51:47 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptrlst;

	ptrlst = lst;
	if (!ptrlst)
		return (0);
	while (ptrlst->next)
		ptrlst = ptrlst->next;
	return (ptrlst);
}
