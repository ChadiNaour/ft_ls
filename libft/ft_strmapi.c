/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:51:05 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 17:25:13 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fraiche;
	unsigned int	i;

	i = 0;
	fraiche = NULL;
	if (s)
	{
		if ((fraiche = (char *)malloc(sizeof(char) *
						(ft_strlen(s) + 1))) == NULL)
			return (NULL);
		while (s[i])
		{
			fraiche[i] = f(i, (char)s[i]);
			i++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (0);
}
