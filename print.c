/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:51:55 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 22:47:32 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

void			display_chmod(char chmod[11], int mode, t_path *path)
{
	chmod[0] = get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	(void)path;
	chmod[10] = get_file_acl(path);
	chmod[11] = '\0';
	if (S_ISUID & mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

void			n_blocks(t_path *path, t_flag *f)
{
	t_path *tmp;

	f->block.blk = 0;
	tmp = path;
	while (tmp)
	{
		if (f->a)
			f->block.blk += tmp->buf.st_blocks;
		else
		{
			if (tmp->content[0] != '.')
				f->block.blk += tmp->buf.st_blocks;
		}
		tmp = tmp->next;
	}
	if ((!f->a && lstlen_l(path)) || (f->a && lstlen(path)))
	{
		ft_putstr("total ");
		ft_putnbr(f->block.blk);
		write(1, "\n", 1);
	}
}

void			ft_print_reg(t_path *tmp, t_flag *f)
{
	if (!f->l && !f->g)
	{
		while (tmp)
		{
			if (f->a)
				ft_color(tmp, f);
			else
			{
				if (tmp->content[0] != '.')
					ft_color(tmp, f);
			}
			tmp = tmp->next;
		}
	}
	else if (f->l || f->g)
	{
		if (f->block.on != 1)
			n_blocks(tmp, f);
		while (tmp)
		{
			ft_aff_l(tmp, f->len, f);
			tmp = tmp->next;
		}
	}
}

void			printing(t_path *p, t_flag *f)
{
	t_path *tmp;

	tmp = p;
	if (!f->l && !f->g)
	{
		if (f->a)
			ft_color(tmp, f);
		else
		{
			if (tmp->content[0] != '.')
				ft_color(tmp, f);
		}
	}
	else if (f->l || f->g)
		ft_aff_l(tmp, f->len, f);
}
