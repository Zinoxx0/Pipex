/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:17 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:46:58 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Adds the element ’new’ at the end(tail) of the list.
void	ft_lstadd_back(t_list **lst, t_list *newvalue)
{
	t_list	*ptrlst;

	if (lst && newvalue)
	{
		if (!*lst)
			*lst = newvalue;
		else
		{
			ptrlst = ft_lstlast(*lst);
			ptrlst->next = newvalue;
		}
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
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/