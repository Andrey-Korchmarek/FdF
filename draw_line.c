//
// Created by Mari Ashley on 8/1/20.
//
#include "fdf.h"

void	draw_line(t_dot start, t_dot end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
	int	color;

	start.x *= data->zoom;
	start.y *= data->zoom;
	end.x *= data->zoom;
	end.y *= data->zoom;
	color = (start.z >= end.z) ? start.color : end->color;
#
	start.x += data->shift_x;
	start.y += data->shift_y;
	end.x += data->shift_x;
	end.y += data->shift_y;
#
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - end.x) || (int)(y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x, start.y, color);
		start.x += x_step;
		start.y += y_step;
	}
	return ;
}
