/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:23:51 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/02 14:40:55 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	if ((ptr = (void *)malloc(sizeof(void) * size)) == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
