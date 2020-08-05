/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:25:48 by mashley           #+#    #+#             */
/*   Updated: 2020/08/03 18:25:51 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_menu(t_fdf txt)
{
	char *str;

	str = "keyboard -> button 'ESC': exit and force quit the mlx window";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 5, 0xFF0000, str);
	str = "mouse  click -> right left & centre; ->"
		" change the angle of 3D map & Fullscreen";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 25, 0x00FF00, str);
	str = "mouse  scroll -> up down -> change zoom of 3D map";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 45, 0x00FF00, str);
	str = "keyboard -> right left, up, down: move the map";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 65, 0x00FFFF, str);
	str = "keyboard ->  'F', 'P': toggle Fullscreen, Projection with default";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 85, 0xFFFFFF, str);
	str = "KB numpad->  + - * / resp.: R-ext; L-shrink;"
		" UP-ext; DN-shr mlx-w";
	mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 115, 0xFFFF00, str);
}
