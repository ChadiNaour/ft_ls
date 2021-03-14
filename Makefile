# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnaour <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 00:35:29 by cnaour            #+#    #+#              #
#    Updated: 2020/03/13 22:43:54 by cnaour           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = ft_ls.h
OBJ = main.o list.o libft/ft_putstr.o libft/ft_putchar.o libft/ft_strdup.o\
	 check_stock.o libft/ft_strchr.o libft/ft_strcmp.o libft/ft_strrchr.o\
	 regular.o libft/ft_putendl.o libft/ft_strdel.o libft/ft_bzero.o \
	 libft/ft_memset.o  list2.o libft/ft_strlen.o libft/ft_strjoin.o \
	 libft/ft_strstr.o	sort.o recursive.o libft/ft_memdel.o sort2.o tab.o\
	 print.o color.o libft/ft_strsub.o list_l.o tools.o print_l.o libft/ft_strsplit.o\
	 libft/ft_wordnum.o libft/ft_charnum.o libft/ft_free_tab.o tools2.o
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
NAME = ft_ls

all : $(NAME)
%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -I $(INC)
	@printf "\033[32mcompilation done\n\033[0m"

clean :
	@rm -f $(OBJ)
	@printf "\033[33mobjects removed\n\033[0m"

fclean : clean
	@rm -f $(NAME)
	@printf "\033[31mbinary file removed\n\033[0m"

re : fclean all
