/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:38:52 by cnaour            #+#    #+#             */
/*   Updated: 2020/03/13 22:54:49 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <errno.h>
# include <sys/acl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define MAJOR(dev) ((unsigned int) ((dev) >> 24))
# define MINOR(dev) ((unsigned int) ((dev) & 0xff))

typedef struct	s_len
{
	unsigned int	link_l;
	unsigned int	owner_l;
	unsigned int	grp_l;
	unsigned int	sfile_l;
	unsigned int	major_l;
	unsigned int	minor_l;
}				t_len;

typedef struct	s_block
{
	int		on;
	int		blk;
}				t_block;

typedef struct	s_flag
{
	int		a;
	int		l;
	int		rm;
	int		r;
	int		t;
	int		f;
	int		sm;
	int		u;
	int		c;
	int		k;
	int		g;
	t_len	len;
	t_block	block;
}				t_flag;

typedef struct	s_path
{
	char			*content;
	char			*stock;
	struct stat		buf;
	struct stat		buff;
	int				type;
	struct s_path	*next;
}				t_path;

int				check(char **av, int ac, t_flag *f, t_path **path);
t_path			*my_lstnew(char *content, struct stat buf, char *stock);
t_path			*my_lstadd_end(t_path *lst, char *content, struct stat buf,
		char *stock);
void			regular(t_path **path, int len, int count, t_flag *f);
t_path			*create_list(char *path, DIR *dir, t_flag *f);
void			ft_print_reg(t_path *p, t_flag *f);
void			sort_list(t_path *p);
int				lstlen(t_path *p);
void			free_list_content(t_path **p);
t_path			*lst_sort(t_path *lst, t_flag *f);
void			recursive(t_path **path, int i, t_flag *f);
int				lstlen(t_path *p);
void			recursive_all(t_path **path, t_flag *f, int i);
t_path			*path_srt(t_path *path, t_flag *f);
void			lst_swap(t_path *p1, t_path *p2);
int				cmp_ts_n(int a, int b, char *s1, char *s2);
t_path			*sort_time(t_path *path, t_flag *f, char type);
void			swap(char **str1, char **str2);
char			**fill_path(int i, int n, char **av);
char			**copy_tab(char **tab);
void			move(char **str);
void			init(t_flag *f);
void			print(char *str);
void			print_error(char *s);
void			ft_color(t_path *p, t_flag *f);
void			ft_cmp_len(t_len *len_t, struct stat buf);
void			ft_final_form(t_len *len_t);
char			*ft_user_id(uid_t st_uid);
char			*ft_grp_id(gid_t st_gid);
int				ft_int_len(int n);
void			ft_aff_l(t_path *lst, t_len len_t, t_flag *f);
void			display_chmod(char chmod[11], int mode, t_path *path);
void			ft_init_len(t_len *len_t);
int				lstlen_l(t_path *p);
void			printing(t_path *p, t_flag *f);
int				aff_file(t_path *p, int k, t_flag *f);
int				is_dir(char *path);
char			get_file_acl(t_path *path);
void			ft_aff_l(t_path *lst, t_len len_t, t_flag *f);
void			ft_help_aff(t_path *lst, t_len len_t, t_flag *f);

#endif
