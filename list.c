/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:47:03 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 18:47:45 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path		*my_lstnew(char *content, struct stat buf, char *stock)
{
	t_path	*fresh;

	fresh = NULL;
	fresh = (t_path *)malloc(sizeof(t_path));
	fresh->content = ft_strdup(content);
	fresh->stock = ft_strdup(stock);
	fresh->buf = buf;
	fresh->next = NULL;
	fresh->type = 0;
	return (fresh);
}

t_path		*my_lstadd_end(t_path *lst, char *content, struct stat buf,
		char *stock)
{
	t_path *new;
	t_path *tmp;

	new = my_lstnew(content, buf, stock);
	if (lst == NULL)
		return (new);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

void		lst_swap(t_path *p1, t_path *p2)
{
	char		*name;
	char		*stock;
	struct stat	tmp;

	name = p1->content;
	tmp = p1->buf;
	stock = p1->stock;
	p1->content = p2->content;
	p1->buf = p2->buf;
	p1->stock = p2->stock;
	p2->content = name;
	p2->buf = tmp;
	p2->stock = stock;
	return ;
}

int			lstlen(t_path *p)
{
	int i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

int			lstlen_l(t_path *p)
{
	int i;

	i = 0;
	while (p)
	{
		if (p->content[0] != '.')
			i++;
		p = p->next;
	}
	return (i);
}
