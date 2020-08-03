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

FILES = ./*/*.c

OFILES = $(patsubst %.c, %.o, $(FILES))

.PHONY: all $(NAME) clean fclean re

all : $(NAME)

%.o : %.c $(HED)
	@$(CC) -c $< -o $@ -I $(HEAD)

$(NAME) : $(OFILES)
	@ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(INCLUDE) $< -c -o $@

clean :
	@$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all