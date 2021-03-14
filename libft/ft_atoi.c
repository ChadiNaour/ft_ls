/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:57:18 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/09 16:15:29 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		help(const char *str, unsigned int i)
{
	int r;

	r = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			r = r * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	return (r);
}

int				ft_atoi(const char *str)
{
	unsigned int	i;
	int				r;
	int				signe;

	signe = 1;
	i = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	r = help(str, i);
	return (signe * r);
}
