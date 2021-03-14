/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 23:10:08 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/11 23:42:25 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstchr(t_list *lst, void *content, size_t content_size)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i = ft_strcmp((const char *)tmp->content, (const char *)content);
		if (i == 0 && tmp->content_size == content_size)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
