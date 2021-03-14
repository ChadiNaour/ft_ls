/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:11:11 by cnaour            #+#    #+#             */
/*   Updated: 2019/04/05 20:14:58 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < -10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(-1 * (n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-1 * n + '0', fd);
	}
}
