/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:50:19 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 22:50:13 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_help_aff_p1(t_path *lst, t_len len_t, t_flag *f)
{
	char			chmod[12];
	char			*str;
	unsigned int	i;
	int				v;

	display_chmod(chmod, lst->buf.st_mode, lst);
	i = 0;
	while (i++ < len_t.link_l - ft_int_len(lst->buf.st_nlink))
		write(1, " ", 1);
	ft_putnbr(lst->buf.st_nlink);
	i = 0;
	write(1, " ", 1);
	if (!f->g)
	{
		str = ft_user_id(lst->buf.st_uid);
		ft_putstr(str);
		while (i++ < (len_t.owner_l - ft_strlen(str)))
			write(1, " ", 1);
	}
	i = 0;
	str = ft_grp_id(lst->buf.st_gid);
	ft_putstr(str);
	v = ft_strlen(str);
	while (i++ < (len_t.grp_l - v))
		write(1, " ", 1);
}

void			ft_help_aff_p21(t_path *lst, t_len len_t)
{
	unsigned int	z;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	if (len_t.major_l > 1 || len_t.minor_l > 1)
		z = 0;
	else
		z = 3;
	j = ft_int_len(lst->buf.st_size);
	while (i++ < len_t.sfile_l + z - j)
		write(1, " ", 1);
	ft_putnbr(lst->buf.st_size);
}

void			ft_help_aff_p2(t_path *lst, t_len len_t)
{
	unsigned int	i;
	unsigned int	z;
	unsigned int	j;

	i = 0;
	if ((S_ISCHR(lst->buf.st_mode) || S_ISBLK(lst->buf.st_mode)))
	{
		j = MAJOR(lst->buf.st_rdev);
		z = ft_int_len(j);
		while (i++ < (len_t.major_l - z))
			write(1, " ", 1);
		ft_putnbr(j);
		write(1, ", ", 2);
		i = 0;
		j = MINOR(lst->buf.st_rdev);
		z = ft_int_len(j);
		while (i++ < (len_t.minor_l - z))
			write(1, " ", 1);
		ft_putnbr(j);
	}
	else
		ft_help_aff_p21(lst, len_t);
	ft_putstr(" ");
}

void			ft_help_aff_p3(t_path *lst)
{
	char	**tab;
	int		time_c;
	int		i;

	time_c = time(NULL);
	tab = ft_strsplit(ctime(&lst->buf.st_mtimespec.tv_sec), ' ');
	ft_putstr(tab[1]);
	ft_putstr(" ");
	if (ft_strlen(tab[2]) <= 1)
		write(1, " ", 1);
	ft_putstr(tab[2]);
	ft_putstr(" ");
	i = 0;
	if ((time_c - lst->buf.st_mtimespec.tv_sec >= 15778476) ||
			(time_c - lst->buf.st_mtimespec.tv_sec <= -15778476))
	{
		ft_putchar(' ');
		while (i < 4)
			ft_putchar(tab[4][i++]);
	}
	else
		while (i < 5)
			ft_putchar(tab[3][i++]);
	ft_free_tab(tab);
	ft_putstr(" ");
}

void			ft_help_aff(t_path *lst, t_len len_t, t_flag *f)
{
	char	*link;

	link = NULL;
	if (lst)
	{
		ft_help_aff_p1(lst, len_t, f);
		ft_help_aff_p2(lst, len_t);
		ft_help_aff_p3(lst);
		(void)f;
		ft_color(lst, f);
	}
}
