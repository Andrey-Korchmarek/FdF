# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mashley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 16:45:10 by mashley           #+#    #+#              #
#    Updated: 2020/08/03 16:45:13 by mashley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=src/*.c
INCS=libft/libft.a minilibx_macos/libmlx.a
FWS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCS) $(FWS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all