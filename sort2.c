/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:51:13 by cnaour            #+#    #+#             */
/*   Updated: 2020/02/04 22:19:19 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_timestap(t_path *path, char type)
{
	int				timestap;

	timestap = -1;
	if (type == 'a')
		timestap = path->buf.st_atime;
	else if (type == 'c')
		timestap = path->buf.st_ctime;
	else if (type == 'm')
		timestap = path->buf.st_mtime;
	return (timestap);
}

t_path			*sort_time(t_path *path, t_flag *f, char type)
{
	t_path		*begin;
	t_path		*tmp;
	int			timestap[2];

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			timestap[0] = get_timestap(path, type);
			timestap[1] = get_timestap(tmp, type);
			if ((cmp_ts_n(timestap[0], timestap[1], path->content,
							tmp->content) > 0 && !f->r))
				lst_swap(path, tmp);
			else if (cmp_ts_n(timestap[0], timestap[1], path->content,
						tmp->content) < 0 && f->r)
				lst_swap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}
