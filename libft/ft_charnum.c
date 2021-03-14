/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charnumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:50:04 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/12 14:21:37 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charnum(const char *s, unsigned int i, char c)
{
	unsigned int nc;

	nc = 0;
	if (s)
	{
		while (s[i] == c)
			i++;
		while (s[i])
		{
			if (s[i] != c)
				nc++;
			else
				break ;
			i++;
		}
		return (nc);
	}
	return (0);
}
