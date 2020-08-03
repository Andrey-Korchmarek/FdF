#include "fdf.h"

static	int		deal_key(int button, t_fdf *data)
{
	if (button == 126)// up button
		data->shift_y -= 10;
	if (button == 125)// down
		data->shift_y += 10;
	if (button == 123)// left
		data->shift_x -= 10;
	if (button == 124)// right
		data->shift_x += 10;
	if (button == 3)// letter F
		new_window(button, data);
	if (button == 69 || button == 78 || button == 67 || button == 75)// + - * / from num
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

int				mouse_press(int button, t_fdf *data)
{
	if (button == 1 || button == 2)
	{
		if (button == 2)
			data->shift_x  += 50;
		if (button == 1)
			if (data->shift_x  > 1)
				data->shift_x  -= 50;
	}
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->shift_y  += 50;
		if (button == 5)
			if (data->shift_y  > 1)
				data->shift_y  -= 50;
	}
	if (button == 3)  //  F
		new_window(button, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void			set_default(t_fdf *data)
{
	data->zoom = 20;
	data->z_scale = 1;
	data->is_isometric = 1;
	data->angle = 0.523599;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr =\
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}
int				main(int argc, char **argv)
{
	t_fdf	karta;
	int		fd;

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
	bresenham(10, 10, 500, 300, karta);
	mlx_key_hook(&karta.win_ptr, deal_key, NULL);//data  i.o NULL
	mlx_loop(&karta.mlx_ptr);
//	draw(karta);
//	mlx_mouse_hook(&karta.win_ptr, mouse_press, data);
	mlx_key_hook(karta.win_ptr, deal_key, NULL);
	ft_free_fdf(&karta);
	fd = 1;
	return (0);
//=======
//    fdf *data;
//
//    if (argc != 2)
//    {
//        char *txt;
//        txt = "Use this command: ./fdf testmap.fdf";
//        printf("%s\n", txt );
//        return (0);
//    }
//    data = (fdf*)malloc(sizeof(fdf));
//    read_file(argv[1], data);
//    set_default(data);
////    data->mlx_ptr = mlx_init();
////   data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1200, "FDF");
////    data->zoom = 20;
////    bresenham(10, 10, 500, 300, data);
//    draw(data);
//    mlx_key_hook(data->win_ptr, deal_key, data);
//    mlx_mouse_hook(data->win_ptr, mouse_press, data);
//    mlx_loop(data->mlx_ptr);
//>>>>>>> master
}
