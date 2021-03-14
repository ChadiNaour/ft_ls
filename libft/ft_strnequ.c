/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:13:23 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:16:40 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		if (res != 0)
			return (0);
		else
			return (1);
	}
	return (0);
}
