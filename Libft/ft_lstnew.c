/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:56:00 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 20:06:38 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// int	main(void)
// {
// 	int	content_value = 42;
// 	t_list	*new_list = ft_lstnew(&content_value);

// 	if (new_list)
// 		printf("List content: %d\n", *((int *)new_list->content));
// 	return 0;
// }