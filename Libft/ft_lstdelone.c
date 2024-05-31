/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:42 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:48:31 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void	*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*
int main()
{
	t_list *lst;
	t_list *newvalue;
	t_list *newvalue2;
	t_list *newvalue3;

	lst = ft_lstnew("first");
	newvalue = ft_lstnew("second");
	newvalue2 = ft_lstnew("third");
	newvalue3 = ft_lstnew("fourth");
	ft_lstadd_back(&lst, newvalue);
	ft_lstadd_back(&lst, newvalue2);
	ft_lstadd_back(&lst, newvalue3);
	ft_lstdelone(lst, free);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/