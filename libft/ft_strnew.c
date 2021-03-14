/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:42:51 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 16:57:39 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = NULL;
	if ((ptr = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	ptr[size] = '\0';
	return (ptr);
}
