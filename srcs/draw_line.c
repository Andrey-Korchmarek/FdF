/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:25:03 by mashley           #+#    #+#             */
/*   Updated: 2020/08/03 18:25:09 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x *= data->zoom;
	start->y *= data->zoom;
	end->x *= data->zoom;
	end->y *= data->zoom;
}

int		get_color(t_dot *start, t_dot *end)
{
	int	color;

	if (start->color == -1 && end->color == -1)
	{
		if (start->z > 0 && end->z > 0)
			return (RED);
		if (start->z < 0 && end->z < 0)
			return (BLUE);
		if (start->z > 0 && end->z < 0)
			return (GREEN);
		if (start->z < 0 && end->z > 0)
			return (GREEN);
		return (WHITE);
	}
	else if (start->color == -1 || end->color == -1)
		color = start->color == -1 ? end->color : start->color;
	else
		color = (start->z >= end->z) ? start->color : end->color;
	return (color);
}

void	isometric(t_dot *start, t_dot *end, t_fdf *data)
{
	if (!data->is_isometric)
		return ;
	start->x = (start->x - start->y) * cos(data->angle);
	start->y = (start->x + start->y) * sin(data->angle) - start->z * 3;
	end->x = (end->x - end->y) * cos(data->angle);
	end->y = (end->x + end->y) * sin(data->angle) - end->z * 3;
}

void	shift(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

void	draw_line(t_dot *start, t_dot *end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;

	if (!(start && end))
		return ;
	zoom(start, end, data);
	color = get_color(start, end);
	isometric(start, end, data);
	shift(start, end, data);
	x_step = end->x - start->x;
	y_step = end->y - start->y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(start->x - end->x) || (int)(start->y - end->y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start->x, start->y, color);
		start->x += x_step;
		start->y += y_step;
	}
	del_dot2(start, end);
}
