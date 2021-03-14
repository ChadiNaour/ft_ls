/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:38:24 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/12 14:21:53 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordnum(const char *s, char c)
{
	unsigned int i;
	unsigned int nm;

	i = 0;
	nm = 0;
	if (s)
	{
		while (s[i] && (s[i] == c))
			i++;
		while (s[i])
		{
			if (s[i] == c && s[i - 1] != c)
				nm++;
			if (!s[i + 1] && s[i] != c)
				nm++;
			i++;
		}
		return (nm);
	}
	return (0);
}
