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

#include "fdf.h"

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

	color = (start->z >= end->z) ? start->color : end->color;
	color = (color == -1) ? 0xFFFFFF : color;
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

void	draw_line(t_dot *start, t_dot *end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;

	zoom(start, end, data);
	color = get_color(start, end);
	isometric(start, end, data);
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
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
}
