/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:52:27 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/18 16:53:12 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa(int n)
{
	char			*fraiche;
	unsigned int	i;

	i = ft_countnumbers(n);
	if ((fraiche = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	if (n == 0)
		*fraiche = '0';
	if (n < 0)
		fraiche[0] = '-';
	fraiche[i] = '\0';
	i--;
	while (n)
	{
		if (n > 0)
			fraiche[i] = (n % 10) + '0';
		else
			fraiche[i] = (-1) * (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (fraiche);
}
