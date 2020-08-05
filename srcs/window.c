/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:29:02 by mashley           #+#    #+#             */
/*   Updated: 2020/08/03 18:29:05 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_win_size(int key, t_fdf *data)
{
	if ((key == 75 && data->win_y <= 500) || (key == 78 && data->win_x <= 500))
		return (1);
	if ((key == 67 && data->win_y > 1000) || (key == 69 && data->win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_fdf *data)
{
	static int old_x;
	static int old_y;

	if (data->win_x != 2560)
	{
		old_x = data->win_x;
		old_y = data->win_y;
	}
	data->win_x = (data->win_x == 2560) ? old_x : 2560;
	data->win_y = (data->win_y == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_fdf *data)
{
	if (check_win_size(key, data))
		return ;
	if (key == 69)
		data->win_x += 100;
	if (key == 78)
		data->win_x -= 100;
	if (key == 67)
		data->win_y += 100;
	if (key == 75)
		data->win_y -= 100;
	if (key == 3)
		full_screen(data);
}

void	new_window(int key, t_fdf *data)
{
	change_window_size(key, data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x,
			data->win_y, "FDF");
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	draw(data);
	mlx_key_hook(data->win_ptr, key_h, data);
	mlx_mouse_hook(data->win_ptr, mouse_h, data);
	mlx_loop(data->mlx_ptr);
}
