int program(int files, char **names)
{
	fdf *data;

	if (files != 2)
	{
		char *txt;
		txt = "Use this command: ./fdf testmap.fdf";
		printf("%s\n", txt );
		return (0);
	}
	data = (fdf*)malloc(sizeof(fdf));
	read_file(names[1], data);

//	set_default(data);
	data->zoom = 40;
//    param->z_scale = 1;
//    param->is_isometric = 1;
//    param->angle = 0.523599;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr =\
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");

//    data->mlx_ptr = mlx_init();
//   data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1200, "FDF");
//    data->zoom = 20;
//    bresenham(10, 10, 500, 300, data);

//	draw(data);
	int x;
	int y;

	print_menu(*data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}

	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_mouse_hook(data->win_ptr, mouse_press, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
