# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mashley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 12:09:43 by mashley           #+#    #+#              #
#    Updated: 2019/10/02 17:06:42 by mashley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./
HEAD = -I libft.h
CC = gcc -Wall -Wextra -Werror
RM = /bin/rm -f

CFILES = ft_atoi.c ft_atoi_base.c ft_free_matrix.c ft_isdigit.c ft_ishex.c ft_ishexlow.c ft_ishexnumber.c ft_ishexup.c ft_islower.c ft_ismark.c ft_isnumber.c ft_ispoint.c ft_issign.c ft_isspace.c ft_memchr.c ft_memdel.c ft_open_read.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strjoin_free.c ft_strjoinfree.c ft_strnew.c ft_strplen.c ft_strsplit.c ft_strstr.c ft_tolower.c gnl.c ft_strequ.c

OFILES = $(patsubst %.c, %.o, $(CFILES))

.PHONY: all $(NAME) clean fclean re

all : $(NAME)

%.o : %.c $(HED)
	@$(CC) -c $< -o $@ -I $(HEAD)

$(NAME) : $(OFILES)
	ar -rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(INCLUDE) $< -c -o $@

$(OFILES):
	$(CC) -c $(CFILES) $(HEAD)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all