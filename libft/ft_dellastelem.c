/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellastelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:36:37 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/11 20:13:16 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dellastelem(t_list *lst)
{
	t_list *tmp;
	t_list *ptr;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	ptr = lst->next;
	while (ptr->next)
	{
		tmp = tmp->next;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	free(ptr);
	return (lst);
}
