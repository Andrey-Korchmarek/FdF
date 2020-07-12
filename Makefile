# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apearl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 14:33:57 by apearl            #+#    #+#              #
#    Updated: 2020/07/12 14:43:11 by apearl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORK=-framework OpenGL -framework AppKit

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc *.c libft/libft.a ./minilibx_macos/libmlx.a $(FRAMEWORK)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
