/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:45:12 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/12 14:06:25 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_countnumbers(int n)
{
	unsigned int	count;
	int				rmp;

	count = 0;
	rmp = n;
	if (rmp == 0)
		return (1);
	while (rmp)
	{
		count++;
		rmp = rmp / 10;
	}
	if (n < 0)
		count++;
	return (count);
}
