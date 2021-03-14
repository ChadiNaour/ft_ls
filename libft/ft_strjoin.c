/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:02:21 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 16:56:26 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*fraiche;

	i = 0;
	j = 0;
	k = 0;
	fraiche = NULL;
	if (s1 && s2)
	{
		if ((fraiche = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
							ft_strlen(s2) + 1))) == NULL)
			return (NULL);
		while (s1[i])
			fraiche[k++] = s1[i++];
		while (s2[j])
			fraiche[k++] = s2[j++];
		fraiche[k] = '\0';
		return (fraiche);
	}
	return (0);
}
