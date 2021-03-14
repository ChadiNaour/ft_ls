/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:48:50 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/10 20:27:35 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_user_id(uid_t st_uid)
{
	struct passwd *pwd;

	if (!(pwd = getpwuid(st_uid)))
		return (NULL);
	return (pwd->pw_name);
}

char		*ft_grp_id(gid_t st_gid)
{
	struct group *grp;

	if (!(grp = getgrgid(st_gid)))
		return (NULL);
	return (grp->gr_name);
}

int			is_dir(char *path)
{
	DIR	*dir;

	if (!(dir = opendir(path)))
		return (!ft_strcmp("Not a directory", strerror(errno)) ? 0 : -1);
	return (!closedir(dir) ? 1 : -1);
}

int			ft_int_len(int n)
{
	int cmp;
	int k;

	if (n == 0)
		return (1);
	cmp = 0;
	k = n;
	while (k)
	{
		cmp++;
		k /= 10;
	}
	if (n < 0)
		cmp++;
	return (cmp);
}
