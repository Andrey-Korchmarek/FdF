/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:25:31 by mashley           #+#    #+#             */
/*   Updated: 2020/08/03 18:25:34 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	del_dot2(t_dot *dot1, t_dot *dot2)
{
	free(dot1);
	dot1 = NULL;
	free(dot2);
	dot2 = NULL;
}

t_dot	*get_dot(int x, int y, t_fdf *data)
{
	t_dot *point;

	point = (t_dot*)malloc(sizeof(t_dot));
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)data->z_matrix[y][x];
	point->color = data->color[y][x];
	return (point);
}
