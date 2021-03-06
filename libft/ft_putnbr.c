/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:05:53 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/05 18:30:30 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < -10)
	{
		ft_putnbr(n / 10);
		ft_putchar(-1 * (n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putchar(-1 * n + '0');
	}
}
