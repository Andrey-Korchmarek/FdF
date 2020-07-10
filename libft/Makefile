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

SRCS = ft_atoi.c ft_atoll.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_ischar.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_range.c ft_shrinking_gap.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_tolower.c ft_toupper.c ft_realloc.c ft_strnlen.c ft_intlen.c ft_abs.c \
ft_memrcpy.c ft_strplen.c ft_lstnew.c ft_lstdel.c ft_strjoinfree.c

OBJ = ft_atoi.o ft_atoll.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
ft_ischar.o ft_isdigit.o ft_islower.o ft_isprint.o ft_isspace.o ft_isupper.o \
ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o \
ft_putstr_fd.o ft_range.o ft_shrinking_gap.o ft_strcat.o ft_strchr.o \
ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
ft_tolower.o ft_toupper.o ft_realloc.o ft_strnlen.o ft_intlen.o ft_abs.o \
ft_memrcpy.o ft_strplen.o ft_lstnew.o ft_lstdel.o ft_strjoinfree.o

INCLUDES = ./

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
