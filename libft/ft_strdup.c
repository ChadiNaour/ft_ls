/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:57:59 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/01 18:06:32 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if ((tab = (char *)malloc(sizeof(*tab) * (i + 1))))
	{
		i = 0;
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}
