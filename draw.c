#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z * 3;
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;

	print_menu(*data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(get_dot(x, y, data), get_dot(x + 1, y, data), data);
			if (y < data->height - 1)
				draw_line(get_dot(x, y, data), get_dot(x, y + 1, data), data);
			x++;
		}
		y++;
	}
}
