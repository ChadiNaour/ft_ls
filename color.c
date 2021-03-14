/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:09:00 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 19:03:17 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_readlink(t_path *path)
{
	char		buff[4096];
	size_t		size;

	if (((path->buf.st_mode) & S_IFMT) == S_IFLNK)
	{
		if (!path)
			size = readlink(path->stock, buff, sizeof(buff));
		else
			size = readlink(path->stock, buff, sizeof(buff));
		ft_putstr(" -> ");
		write(1, buff, size);
	}
	return (NULL);
}

static void	ft_color2(struct stat sb, char *stock)
{
	if (((sb.st_mode) & S_IFMT) == S_IFCHR)
	{
		ft_putstr("\033[43m");
		ft_putstr("\033[34m");
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFBLK)
	{
		ft_putstr("\033[34m");
		ft_putstr("\033[106m");
	}
	else if (((sb.st_mode) & S_ISUID) && ((sb.st_mode) & S_IXUSR))
	{
		ft_putstr("\033[0;30m");
		ft_putstr("\033[41m");
	}
	else if ((sb.st_mode) & S_IXUSR)
		ft_putstr("\033[0;31m");
	ft_putstr(stock);
	ft_putstr("\033[0m");
}

int			ft_color3(struct stat sb, int x)
{
	if ((S_ISDIR(sb.st_mode)) && ((sb.st_mode) & S_IWUSR)
			&& ((sb.st_mode) & S_IWGRP) && ((sb.st_mode) & S_IWOTH))
	{
		ft_putstr("\033[0;30m");
		ft_putstr("\033[43m");
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFDIR)
	{
		ft_putstr("\033[1;36m");
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFSOCK)
	{
		ft_putstr("\033[0;32m");
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFLNK)
	{
		ft_putstr("\033[0;35m");
		x++;
	}
	return (x);
}

void		ft_color(t_path *p, t_flag *f)
{
	int		x;

	x = 0;
	x = ft_color3(p->buf, x);
	x == 0 ? ft_color2(p->buf, p->content) : ft_putstr(p->content);
	ft_putstr("\033[0m");
	(void)f;
	if ((((p->buf.st_mode) & S_IFMT) == S_IFLNK) && (f->l || f->g))
		ft_readlink(p);
	ft_putstr("\n");
}
