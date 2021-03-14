/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:55:57 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/10 20:26:39 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			link_file(t_flag *f, t_path *tmp, int k)
{
	if ((f->l || f->g) && S_ISLNK(tmp->buf.st_mode) &&
			ft_strcmp(tmp->content, "/"))
	{
		if (tmp->content[ft_strlen(tmp->content) - 1] != '/')
		{
			ft_cmp_len(&f->len, tmp->buf);
			f->block.on = 1;
		}
		tmp->type = 1;
		k++;
	}
	if (is_dir(tmp->content) != 1)
	{
		tmp->type = 1;
		if (f->l || f->g)
		{
			f->block.on = 1;
			ft_cmp_len(&f->len, tmp->buf);
		}
		k++;
	}
	return (k);
}

void		printing_files(t_path *tmp, t_flag *f)
{
	while (tmp)
	{
		if (tmp->type == 1)
			printing(tmp, f);
		tmp = tmp->next;
	}
}

int			aff_file(t_path *p, int k, t_flag *f)
{
	t_path		*tmp;

	tmp = p;
	ft_init_len(&f->len);
	while (tmp)
	{
		lstat(tmp->content, &tmp->buf);
		if (S_ISLNK(tmp->buf.st_mode))
			k = link_file(f, tmp, k);
		else if (!S_ISDIR(tmp->buf.st_mode))
		{
			tmp->type = 1;
			if (f->l || f->g)
			{
				f->block.on = 1;
				ft_cmp_len(&f->len, tmp->buf);
			}
			k++;
		}
		tmp = tmp->next;
	}
	if (f->l || f->g)
		ft_final_form(&f->len);
	printing_files(p, f);
	return (k);
}

int			dir_isregular(t_path *tmp, int len, t_path *p, t_flag *f)
{
	DIR *dir;

	f->block.on = 0;
	if (len > 1)
	{
		if (f->k)
			ft_putchar('\n');
		print(tmp->content);
	}
	if ((dir = opendir(tmp->content)))
	{
		if (f->l || f->g)
			ft_init_len(&f->len);
		p = create_list(tmp->content, dir, f);
		if (f->l || f->g)
			ft_final_form(&f->len);
		p = path_srt(p, f);
		ft_print_reg(p, f);
		free_list_content(&p);
		closedir(dir);
	}
	else
		print_error(tmp->content);
	f->k++;
	return (f->k);
}

void		regular(t_path **path, int len, int count, t_flag *f)
{
	t_path		*tmp;
	t_path		*p;

	p = NULL;
	tmp = *path;
	while (tmp && count)
	{
		if (tmp->type == 0)
			f->k = dir_isregular(tmp, len, p, f);
		count--;
		tmp = tmp->next;
	}
}
