/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:32:05 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/12 16:21:03 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *fresh;

	ptr = NULL;
	fresh = NULL;
	if (!lst)
		return (NULL);
	ptr = ft_lstnew(f(lst)->content, f(lst)->content_size);
	fresh = ptr;
	while (lst->next)
	{
		ptr->next = ft_lstnew(f(lst->next)->content
				, f(lst->next)->content_size);
		ptr = ptr->next;
		lst = lst->next;
	}
	return (fresh);
}
