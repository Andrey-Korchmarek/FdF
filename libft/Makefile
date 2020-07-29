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

FILES = ft_abs.c ft_atoi.c ft_atoi_base.c ft_atoll.c ft_bzero.c ft_free_array.c ft_free_matrix.c ft_intlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_ischar.c ft_isdigit.c ft_ishex.c ft_ishexlow.c ft_ishexnumber.c ft_ishexup.c ft_islower.c ft_ismark.c ft_isnumber.c ft_ispoint.c ft_isprint.c ft_issign.c ft_isspace.c ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memrcpy.c ft_memset.c ft_open_read.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_range.c ft_realloc.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcount.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinfree.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnlen.c ft_strnstr.c ft_strplen.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c

#CFILES = $(patsubst %, $(SRCS)%.c, $(FILES))
OFILES = $(patsubst %.c, %.o, $(FILES))

.PHONY: all $(NAME) clean fclean re

all : $(NAME)

%.o : %.c $(HED)
	@$(CC) -c $< -o $@ -I $(HEAD)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(INCLUDE) $< -c -o $@

# $(OFILES) :
# 	$(CC) -c $(CFILES) $(HEAD)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all