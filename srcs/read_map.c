/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:28:06 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:28:10 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	read_map(char *file, t_fdf *map)
{
	int		param[2];

	param[0] = get_height_and_width(file, 0);
	param[1] = get_height_and_width(file, 1);
	(*map).height = param[0];
	(*map).width = param[1];
	(*map).z_matrix = (int **)malloc(sizeof(int*) * ((*map).height + 1));
	(*map).color = (int **)malloc(sizeof(int*) * ((*map).height + 1));
	get_z_matrix(file, map);
	(*map).mlx_ptr = NULL;
	(*map).win_ptr = NULL;
	return ;
}
