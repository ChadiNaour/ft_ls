/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:43:18 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 22:50:38 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
}

void			print_error(char *s)
{
	ft_putstr("ft_ls: ");
	if (ft_strchr(s, '/'))
		perror(ft_strrchr(s, '/') + 1);
	else
		perror(s);
}

void			ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < -10)
	{
		ft_putnbr(n / 10);
		ft_putchar(-1 * (n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putchar(-1 * n + '0');
	}
}

char			get_file_acl(t_path *path)
{
	acl_t	tmp;
	char	buf[4096];

	if (listxattr(path->stock, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path->stock, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

void			ft_aff_l(t_path *lst, t_len len_t, t_flag *f)
{
	if (lst)
	{
		if (f->a || lst->content[0] != '.')
			ft_help_aff(lst, len_t, f);
	}
}
