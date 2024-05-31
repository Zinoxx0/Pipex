/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:05:47 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:47:32 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*ptrlst;
	t_list	*tmp;

	ptrlst = *lst;
	while (ptrlst)
	{
		tmp = ptrlst->next;
		ft_lstdelone(ptrlst, del);
		ptrlst = tmp;
	}
	*lst = 0;
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
	ft_lstclear(&lst, free);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/