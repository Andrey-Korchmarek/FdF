/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:01:12 by mashley           #+#    #+#             */
/*   Updated: 2020/08/01 13:01:18 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int button, fdf *data)
{
	if (button == 126)
		data->shift_y -= 10;
	if (button == 125)
		data->shift_y += 10;
	if (button == 123)
		data->shift_x -= 10;
	if (button == 124)
		data->shift_x += 10;
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

int		mouse_press(int button, int x, int y, fdf *data)
{
	if (button == 1 || button == 2)
	{
		if (button == 2)
			data->shift_x += 50;
		if (button == 1)
			if (data->shift_x > 1)
				data->shift_x -= 50;
	}
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->shift_y += 50;
		if (button == 5)
			if (data->shift_y > 1)
				data->shift_y -= 50;
	}
	if (button == 3)
		new_window(button, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	x = 0;
	y = 0;
	return (0);
}

void	set_default(fdf *data)
{
	data->zoom = 40;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr =\
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}

int		main(int argc, char **argv)
{
	fdf		*data;
	char	*txt;

	if (argc != 2)
	{
		txt = "Use this command: ./fdf testmap.fdf";
		printf("%s\n", txt);
		return (0);
	}
	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	set_default(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_mouse_hook(data->win_ptr, mouse_press, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
