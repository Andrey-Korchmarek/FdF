//
// Created by Mari Ashley on 8/1/20.
//

#include "fdf.h"

t_dot	*get_dot(int x, int y, t_fdf *data)
{
	t_dot *point;

	point = (t_dot*)malloc(sizeof(t_dot));
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)data->z_matrix[y][x];
	point->color = data->color[y][x];

//	point->shift_x = data->shift_x;
//	point->shift_y = data->shift_y;
//
//	point->win_x = data->win_x;
//	point->win_y = data->win_y;
//
//	point->mlx_ptr = data->mlx_ptr;
//	point->win_ptr = data->win_ptr;
	return (point);
}