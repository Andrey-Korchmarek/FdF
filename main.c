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

void	set_default(t_fdf *data)
{
	data->zoom = 5;
	data->angle = 0.523599;
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
	t_fdf	*data;
	int		fd;

	if (argc != 2)
		game_over(1);
	if (!ft_strequ(ft_strstr(argv[1], ".fdf"), ".fdf"))
		game_over(5);
	if (!(fd = ft_open_read(argv[1])))
		game_over(2);
	close(fd);
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	set_default(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_h, data);
	mlx_mouse_hook(data->win_ptr, mouse_h, data);
	mlx_loop(data->mlx_ptr);
	ft_free_fdf(data);
	return (0);
}
