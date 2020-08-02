/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:12:28 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:12:59 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		deal_key(int button, t_fdf *data)
{
	if (button == 126)
		data->shift_y -= 10;
	if (button == 125)
		data->shift_y += 10;
	if (button == 123)
		data->shift_x -= 10;
	if (button == 124)
		data->shift_x += 10;
//	if (button == 3)
//		new_window(button, data);
//	if (button == 69 || button == 78 || button == 67 || button == 75)
//		new_window(button, data);
	if (button == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
//	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	karta;
	int 	fd;

	if (argc != 2)
		game_over(1);
	if (!(fd = ft_open_read(argv[1])))
		game_over(2);
	close(fd);
	read_map(argv[1], &karta);
#ifdef TEST
	int i;
	int j;

	i = 0;
	while (i < karta.height)
	{
		j = 0;
		while (j < karta.width)
		{
			printf("%3d", karta.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < karta.height)
	{
		j = 0;
		while (j < karta.width)
		{
			printf("%3d ", karta.color[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
#endif
	set_default(&karta);
	karta.mlx_ptr = mlx_init();
	karta.win_ptr = mlx_new_window(karta.mlx_ptr, 1000, 1000, "FDF");
//	bresenham(10, 10, 500, 300, karta);
//	mlx_key_hook(&karta.win_ptr, deal_key, NULL);//data  i.o NULL
	mlx_loop(&karta.mlx_ptr);
//	draw(karta);
//	mlx_mouse_hook(&karta.win_ptr, mouse_press, data);
	mlx_key_hook(karta.win_ptr, deal_key, NULL);
	ft_free_fdf(&karta);
	fd = 1;
	return (0);
}
