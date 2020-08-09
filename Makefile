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

.PHONY: clean fclean re
NAME = fdf
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
FWS = -lmlx -lXext -lX11 -lm

MY_LIB = ./libft/
MLX_LIB = ./minilibx_linux/
INC = ./minilibx_linux/ ./libft/includes/ ./includes
INCLUDES = -I ./minilibx_linux/ -I ./libft/includes/ -I ./includes/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

SRC_DIR = ./srcs
OBJ_DIR = ./object

SRC_NAME = draw.c draw_line.c ft_free_fdf.c ft_spnbrcount.c game_over.c get_dot.c get_height_and_width.c \
get_z_matrix.c hooks.c print_menu.c read_map.c window.c main.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make build_lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) $(FWS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

build_lib:
	@make -sC $(MY_LIB)
	@make -sC $(MLX_LIB)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_LIB)
	@make clean -C $(MY_LIB)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(MY_LIB)

re:	fclean all
