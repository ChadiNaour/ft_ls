/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:34:25 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/10 13:38:40 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    recursive(t_path **path ,int i, t_flag *f)
{
    t_path *tmp;
    DIR *dir;
    tmp = *path;
    char *str;
    char *tmp1;
    struct stat buff;
    t_path *ret;
    t_path *p;
    t_path *x;

    ret = NULL;
    if (i == 0)
    {
        regular(&tmp, 0, 1, f);
        i++;
    }
    else
    {
            regular(&tmp, 2, 1, f);
    }
    if (tmp && S_ISDIR(tmp->buf.st_mode))
    {
        if ((dir = opendir(tmp->content)))
        {
            p = NULL;
            p = create_list(tmp->content, dir, f);
            x = p;
            p = path_srt(p, f);
            while (p)
            {
                if (ft_strcmp(p->content, ".") && ft_strcmp(p->content, ".."))
                {
                    if (!ft_strcmp(tmp->content, "/"))
                        str = ft_strjoin(tmp->content,p->content);
                    else
                        str = ft_strjoin((tmp1 = ft_strjoin(tmp->content, "/")), p->content);
                    lstat(str, &buff);
                    if (!f->a)
                    {
                        if (!ft_strstr(str, "/.") && S_ISDIR(buff.st_mode))
                        {
                            if (ret)
                                free_list_content(&ret);
                            ret = my_lstnew(str, buff, str);
                            recursive(&ret, i, f);
                            if (ret)
                                free_list_content(&ret);
                        }
                    }
                    else
                    {
                        if (S_ISDIR(buff.st_mode))
                        {
                            if (ret)
                                free_list_content(&ret);
                            ret = my_lstnew(str, buff, str);
                            recursive(&ret, i, f);
                            if (ret)
                                free_list_content(&ret);
                        }

                    }
                    ft_strdel(&str);
                    ft_strdel(&tmp1);
                }
                p = p->next;
            }
            free_list_content(&x);
            closedir(dir);
        }
    }
}

void	recursive_all(t_path **path, t_flag *f, int i)
{
    t_path *begin;

    begin = *path;
    if (lstlen(*path) == 1 || lstlen(*path) == 0)
        recursive(&begin, i, f);
    else
    {
        while (begin)
        {
            if (begin->type == 0)
            {
                recursive(&begin, 1, f);
            }
            begin = begin->next;
        }
    }
}
