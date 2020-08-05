/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:36:14 by mashley           #+#    #+#             */
/*   Updated: 2020/08/05 20:36:19 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		key_h(int button, t_fdf *data)
{
	if (button == 126 || button == 13)
		data->shift_y -= 10;
	if (button == 125 || button == 1)
		data->shift_y += 10;
	if (button == 123 || button == 0)
		data->shift_x -= 10;
	if (button == 124 || button == 2)
		data->shift_x += 10;
	if (button == 35)
		data->is_isometric = (data->is_isometric == 0) ? 1 : 0;
	if (button == 3)
		new_window(button, data);
	if (button == 69 || button == 78 || button == 67 || button == 75)
		new_window(button, data);
	if (button == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		mouse_h(int button, int x, int y, t_fdf *data)
{
	if (button == 1 || button == 2)
	{
		if (button == 2)
			data->angle += 0.1;
		if (button == 1)
			data->angle -= 0.1;
	}
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->zoom -= 1;
		if (button == 5)
			data->zoom += 1;
	}
	if (button == 3)
		new_window(button, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	x = 0;
	y = 0;
	return (0);
}
