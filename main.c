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

int	main(int argc, char **argv)
{
	t_fdf	karta;
#ifdef TEST
	int i;
	int j;
#endif

	if (argc != 2)
		game_over(1);
	read_map(argv[1], &karta);
#ifdef TEST
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
//	set_default(&karta);
//	karta.mlx_ptr = mlx_init();
//	karta.win_ptr = mlx_new_window(karta.mlx_ptr, 1000, 1000, "FDF");
//	mlx_loop(&karta.mlx_ptr);
//	draw(&karta);
//	mlx_key_hook(&karta.win_ptr, deal_key, data);
//	mlx_mouse_hook(&karta.win_ptr, mouse_press, data);
//	bresenham(10, 10, 500, 300, karta);
	ft_free_fdf(&karta);
	return (0);
}
