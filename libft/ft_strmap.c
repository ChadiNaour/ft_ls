/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:01:00 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:25:00 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		i;

	i = 0;
	fraiche = NULL;
	if (s)
	{
		if ((fraiche = (char *)malloc(sizeof(char) *
						(ft_strlen(s) + 1))) == NULL)
			return (NULL);
		while (s[i])
		{
			fraiche[i] = f((char)s[i]);
			i++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (0);
}
