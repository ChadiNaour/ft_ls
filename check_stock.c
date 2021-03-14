/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:02:12 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 23:06:58 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'a' && str[i] != 'R' && str[i] != 't' &&
				str[i] != 'l' && str[i] != 'r' && str[i] != 'f'
				&& str[i] != 'S' && str[i] != 'c' && str[i] != 'u'
				&& str[i] != 'g')
			return (str[i]);
		i++;
	}
	return ('\0');
}

void	chose_flag(char **tab, t_flag *f, int i)
{
	if (ft_strchr(tab[i], 'a'))
		f->a = 1;
	if (ft_strchr(tab[i], 'l'))
		f->l = 1;
	if (ft_strchr(tab[i], 'R'))
		f->rm = 1;
	if (ft_strchr(tab[i], 'r'))
		f->r = 1;
	if (ft_strchr(tab[i], 't'))
		f->t = 1;
	if (ft_strchr(tab[i], 'f'))
	{
		f->f = 1;
		f->a = 1;
	}
	if (ft_strchr(tab[i], 'S'))
		f->sm = 1;
	if (ft_strchr(tab[i], 'c'))
		f->c = 1;
	if (ft_strchr(tab[i], 'u'))
		f->u = 1;
	if (ft_strchr(tab[i], 'g'))
		f->g = 1;
}

int		check_error(t_flag **f, char **av, int i)
{
	while (av[i])
	{
		if (av[i][0] == '-' && av[i][1])
		{
			if (av[i][1] == '-')
			{
				i++;
				break ;
			}
			if (check_arg(&av[i][1]))
			{
				ft_putstr("ft_ls: illegal option -- ");
				ft_putchar(check_arg(&av[i][1]));
				ft_putstr("\nusage: ls [-RSalrtfgcu] [file ...]\n");
				exit(0);
			}
			chose_flag(av, *f, i);
			i++;
		}
		else
			break ;
	}
	return (i);
}

int		fill_list(char **tmp, t_path **path, int e)
{
	int			j;
	struct stat	buff;
	int			k;
	char		*tmp2;

	j = 0;
	k = 0;
	while (tmp[j])
	{
		tmp2 = (is_dir(tmp[j]) == 1) ? ft_strjoin(tmp[j], "/") :
			ft_strdup(tmp[j]);
		if (lstat(tmp2, &buff))
		{
			ft_putstr("ft_ls: ");
			perror(tmp[j]);
			j++;
			e++;
		}
		else
		{
			if (!k++)
				*path = my_lstnew(tmp[j], buff, tmp[j]);
			else
			my_lstadd_end(*path, tmp[j], buff, tmp[j]);
			j++;
		}
		ft_strdel(&tmp2);
	}
	return (e);
}

int		check(char **av, int ac, t_flag *f, t_path **path)
{
	char		**tmp;
	int			e;
	int			j;

	e = 0;
	tmp = NULL;
	j = 1;
	j = check_error(&f, av, j);
	tmp = fill_path(j, ac, av);
	e = fill_list(tmp, path, e);
	*path = path_srt(*path, f);
	free(tmp);
	return (e);
}
