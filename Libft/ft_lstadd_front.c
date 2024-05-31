/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:59:20 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/18 13:47:20 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Adds the element ’new’ at the beginning(head) of the list.
void	ft_lstadd_front(t_list **lst, t_list *newvalue)
{
	if (lst && newvalue)
	{
		newvalue->next = *lst;
		*lst = newvalue;
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
	ft_lstadd_front(&lst, newvalue);
	ft_lstadd_front(&lst, newvalue2);
	ft_lstadd_front(&lst, newvalue3);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/