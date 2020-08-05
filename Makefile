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

NAME = fdf
SRC = srcs/draw.c srcs/draw_line.c srcs/ft_free_fdf.c srcs/ft_spnbrcount.c srcs/game_over.c srcs/get_dot.c srcs/get_height_and_width.c srcs/get_z_matrix.c srcs/print_menu.c srcs/read_map.c srcs/window.c main.c
OBJ = $(patsubst %.c, %.o, $(SRC))
INCS = libft/libft.a minilibx_macos/libmlx.a
FWS = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall
HEAD = -I fdf.h

.PHONY: all clean fclean re

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(HEAD) $(INCS) $(FWS)

%.o : %.c $(HEAD)
	@gcc -c $< -o $@ $(HEAD)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@/bin/rm -r $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all