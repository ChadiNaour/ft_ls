/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:23:41 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:09:15 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*fraiche;

	i = 0;
	if (s)
	{
		if ((fraiche = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (s[i] && i < len)
		{
			fraiche[i] = s[start];
			i++;
			start++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (0);
}
