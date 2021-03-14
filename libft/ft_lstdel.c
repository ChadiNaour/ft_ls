/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:57:48 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/08 13:52:09 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *nxt;

	ptr = NULL;
	nxt = NULL;
	ptr = *alst;
	while (ptr)
	{
		nxt = ptr->next;
		(*del)(ptr->content, ptr->content_size);
		free(ptr);
		ptr = nxt;
	}
	*alst = NULL;
}
