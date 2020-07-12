# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mashley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 12:34:51 by mashley           #+#    #+#              #
#    Updated: 2020/07/08 12:34:58 by mashley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FRAEMWORKS=-framework OpenGL -framework AppKit
CCFL = gcc -Wall -Wextra -Werror
SRCS = main.c ./srcs/*.c
OBJ = $(patsubst %.c,%.o,$(SRCS))
INCL = -I. -Ilibft -Iminilibx_macos
LIBRARIES = -Llibft -Lminilibx_macos -lft -lmlx -lm
MINILIBX_DIR = ./minilibx_macos
LIBFT_DIR = ./libft

.PHONY: all $(NAME) clean fclean re push

all: $(NAME)

$(NAME): libftt minilibx $(OBJ)
	@$(CCFL) $(LIBRARIES) $(INCL) $(OBJ)
	@mv ./a.out $(NAME)

%.o: %.c
	@$(CCFL) $(INCL) $< -c -o $@

clean:
	@/bin/rm -f *.o
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

minilibx:
	@$(MAKE) -C $(MINILIBX_DIR)

libftt:
	@$(MAKE) -C $(LIBFT_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(MINILIBX_DIR)/libmlx.a
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

push:
    @git add .
    git status -s
    @git commit -m "make push"
    @git push origin master