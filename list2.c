/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:02:01 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 14:06:03 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_join_path(char *str, char *tmp, char *name, char *path)
{
	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		str = ft_strjoin(tmp, name);
	}
	else
		str = ft_strjoin(path, name);
	ft_strdel(&tmp);
	return (str);
}

t_path		*create_node(char *path, char *name, t_flag *f, t_path *p)
{
	struct stat	buff;
	char		*str;
	char		*tmp;

	str = NULL;
	tmp = NULL;
	str = ft_join_path(str, tmp, name, path);
	if (lstat(str, &buff) != -1)
	{
		p = my_lstnew(name, buff, str);
		if ((f->l || f->g) && f->a)
			ft_cmp_len(&f->len, buff);
		if ((f->l || f->g) && !f->a)
			if (name[0] != '.')
				ft_cmp_len(&f->len, buff);
		ft_strdel(&str);
	}
	else
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (p);
}

t_path		*create_list(char *path, DIR *dir, t_flag *f)
{
	struct dirent	*sd;
	t_path			*p;
	t_path			*tmp1;
	t_path			*tmp2;

	p = NULL;
	if ((sd = readdir(dir)) != NULL)
	{
		if (!(p = create_node(path, sd->d_name, f, p)))
			return (NULL);
		tmp1 = p;
	}
	while ((sd = readdir(dir)) != NULL)
	{
		if (!(tmp2 = create_node(path, sd->d_name, f, tmp1)))
			return (NULL);
		tmp1->next = tmp2;
		tmp1 = tmp1->next;
	}
	return (p);
}

void		free_list_content(t_path **p)
{
	t_path	*t;

	while (*p)
	{
		t = (*p)->next;
		ft_strdel(&(*p)->content);
		ft_strdel(&(*p)->stock);
		free(*p);
		*p = t;
	}
	*p = NULL;
}

int			cmp_ts_n(int a, int b, char *s1, char *s2)
{
	return (a == b ? ft_strcmp(s1, s2) : b - a);
}
