/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:31 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/08 16:06:54 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ptr;
	t_list *nxt;

	ptr = NULL;
	nxt = NULL;
	ptr = lst;
	while (ptr)
	{
		nxt = ptr->next;
		f(ptr);
		ptr = nxt;
	}
}
