/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:36:33 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 23:03:48 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init(t_flag *f)
{
	f->a = 0;
	f->l = 0;
	f->r = 0;
	f->rm = 0;
	f->t = 0;
	f->f = 0;
	f->sm = 0;
	f->u = 0;
	f->c = 0;
	f->g = 0;
	f->k = 0;
	f->block.on = 0;
	f->block.blk = 0;
}

void	ft_init_len(t_len *len_t)
{
	len_t->link_l = 0;
	len_t->owner_l = 0;
	len_t->grp_l = 0;
	len_t->sfile_l = 0;
	len_t->major_l = 0;
	len_t->minor_l = 0;
}

int		main(int ac, char **av)
{
	static int	i;
	struct stat	buf;
	t_flag		*f;
	t_path		*path;

	if (ac >= 1)
	{
		i = 0;
		path = NULL;
		f = malloc(sizeof(t_flag));
		init(f);
		(f->l || f->g) ? ft_init_len(&f->len) : 1;
		i = check(av, ac, f, &path);
		if (!path && !i)
		{
			lstat(".", &buf);
			path = my_lstnew(".", buf, ".");
		}
		f->k = aff_file(path, f->k, f);
		(!f->rm) ? regular(&path, lstlen(path) + i, lstlen(path), f) :
			recursive_all(&path, f, i);
		free_list_content(&path);
		free(f);
	}
}
