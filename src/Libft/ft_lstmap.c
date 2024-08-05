/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:07:52 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:51:18 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*ptrnewlist;

	newlist = NULL;
	while (lst)
	{
		ptrnewlist = ft_lstnew(f(lst->content));
		if (!ptrnewlist)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, ptrnewlist);
		lst = lst->next;
	}
	return (newlist);
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
	ft_lstmap(lst, ft_toupper, free);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/