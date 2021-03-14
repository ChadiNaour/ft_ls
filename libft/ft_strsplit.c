/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:46:42 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:26:29 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**fraiche;

	i = 0;
	j = 0;
	fraiche = NULL;
	if (!s)
		return (0);
	if ((fraiche = (char **)malloc(sizeof(char *) *
					(ft_wordnum(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i] && j < (unsigned int)ft_wordnum(s, c))
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			fraiche[j++] = ft_strsub(s, i, ft_charnum(s, i, c));
			i = i + ft_charnum(s, i, c);
		}
	}
	fraiche[j] = NULL;
	return (fraiche);
}
