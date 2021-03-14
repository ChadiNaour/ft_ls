/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:58 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/09 23:50:37 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path		*lst_sort(t_path *lst, t_flag *f)
{
	t_path	*begin;
	t_path	*tmp;

	tmp = NULL;
	begin = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if ((ft_strcmp(lst->content, tmp->content) > 0 && !f->r) ||
					(ft_strcmp(lst->content, tmp->content) < 0 && f->r))
				lst_swap(lst, tmp);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (begin);
}

t_path		*sort_size(t_path *path, t_flag *f)
{
	t_path		*begin;
	t_path		*tmp;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if ((cmp_ts_n(path->buf.st_size, tmp->buf.st_size, path->content,
							tmp->content) > 0 && !f->r) ||
				(cmp_ts_n(path->buf.st_size, tmp->buf.st_size, path->content,
							tmp->content) < 0 && f->r))
				lst_swap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

t_path		*path_srt(t_path *path, t_flag *f)
{
	t_path		*sort;

	if (f->f)
		sort = path;
	else if (f->sm)
		sort = sort_size(path, f);
	else if (f->t)
	{
		if (f->c)
			sort = sort_time(path, f, 'c');
		else if (f->u)
			sort = sort_time(path, f, 'a');
		else
			sort = sort_time(path, f, 'm');
	}
	else
		sort = lst_sort(path, f);
	return (sort);
}
