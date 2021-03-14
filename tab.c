/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:47:14 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/09 23:49:35 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(char **str1, char **str2)
{
	char *temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

char	**fill_path(int i, int n, char **av)
{
	char	**path;
	int		j;

	j = 0;
	path = malloc(sizeof(char *) * n - i);
	while (i < n)
	{
		path[j] = av[i];
		i++;
		j++;
	}
	path[j] = NULL;
	return (path);
}

void	move(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) < 0)
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}
