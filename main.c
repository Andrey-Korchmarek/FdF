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
static int deal_key(int key)
{
    printf("%d", key);
    return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	karta;
	int 	fd;

	if (argc != 2)
		game_over(1);
	if (!(fd = ft_open_read(argv[1])))
		game_over(5);
	close(fd);
	read_map(argv[1], &karta);
	set_default(&karta);
	karta.mlx_ptr = mlx_init();
	karta.win_ptr = mlx_new_window(karta.mlx_ptr, 1000, 1000, "FDF");
//	bresenham(10, 10, 500, 300, karta);
//	mlx_key_hook(&karta.win_ptr, deal_key, NULL);//data  i.o NULL
	mlx_loop(&karta.mlx_ptr);
//	draw(karta);
//	mlx_mouse_hook(&karta.win_ptr, mouse_press, data);
	ft_free_fdf(&karta);
	fd = deal_key(1);
	return (0);
}
