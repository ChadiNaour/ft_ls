/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:04:20 by cnaour            #+#    #+#             */
/*   Updated: 2019/03/31 16:32:39 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*rmp;

	rmp = (unsigned char *)b;
	i = 0;
	while (i < len)
		rmp[i++] = (unsigned char)c;
	b = (void *)rmp;
	return (b);
}
