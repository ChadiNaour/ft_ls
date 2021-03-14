/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:00:02 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:09:32 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*cas_x(void)
{
	char	*fraiche;

	fraiche = NULL;
	if ((fraiche = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	*fraiche = '\0';
	return (fraiche);
}

char			*ft_strtrim(char const *s)
{
	char			*fraiche;
	unsigned int	beg;
	unsigned int	fin;

	if (s)
	{
		fraiche = NULL;
		beg = 0;
		fin = ft_strlen(s) - 1;
		if (!*s)
			return (cas_x());
		while (s[beg] && (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t'))
			beg++;
		if (s[beg] == '\0')
			return (cas_x());
		while (s[fin] && (s[fin] == ' ' || s[fin] == '\n' || s[fin] == '\t')
				&& fin > beg)
			fin--;
		fraiche = ft_strsub(s, beg, (fin - beg + 1));
		return (fraiche);
	}
	return (0);
}
