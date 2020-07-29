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

FILES = ft_abs ft_atoi ft_atoll ft_bzero ft_intlen ft_isalnum ft_isalpha ft_isascii \
ft_ischar ft_isdigit ft_islower ft_isprint ft_isspace ft_isupper ft_itoa ft_lstadd \
ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc ft_memccpy ft_memchr \
ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memrcpy ft_memset ft_putchar ft_putchar_fd \
ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_range \
ft_realloc ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strjoinfree \
ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ \
ft_strnew ft_strnlen ft_strnstr ft_strplen ft_strrchr ft_strsplit ft_strstr ft_strsub \
ft_strtrim ft_tolower ft_toupper get_next_line ft_wdcounter

#CFILES = $(patsubst %, $(SRCS)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

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