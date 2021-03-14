/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:55:09 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 17:57:50 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_cmp_len(t_len *len_t, struct stat buf)
{
	unsigned int	v;

	if (len_t->link_l < buf.st_nlink)
		len_t->link_l = buf.st_nlink;
	if (len_t->sfile_l < buf.st_size)
		len_t->sfile_l = buf.st_size;
	if (len_t->owner_l < (v = ft_strlen(ft_user_id(buf.st_uid))))
		len_t->owner_l = v;
	if (len_t->grp_l < (v = ft_strlen(ft_grp_id(buf.st_gid))))
		len_t->grp_l = v;
	if ((S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)))
	{
		if ((len_t->major_l < (v = MAJOR(buf.st_rdev))))
			len_t->major_l = v;
		if ((len_t->minor_l < (v = MINOR(buf.st_rdev))))
			len_t->minor_l = v;
	}
}

void		ft_final_form(t_len *len_t)
{
	len_t->link_l = ft_int_len(len_t->link_l) + 1;
	len_t->major_l = ft_int_len(len_t->major_l);
	len_t->minor_l = ft_int_len(len_t->minor_l);
	len_t->sfile_l = ft_int_len(len_t->sfile_l) +
		len_t->major_l + len_t->minor_l - 4;
	len_t->owner_l += 2;
	len_t->grp_l += 1;
}
