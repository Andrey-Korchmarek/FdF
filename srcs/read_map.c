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

#include "../includes/fdf.h"

void	read_map(char *file, t_fdf *map)
{
	map->height = get_height_and_width(file);
	map->width = get_height_and_width(file);
	map->z_matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
	map->color = (int **)malloc(sizeof(int*) * (map->height + 1));
	get_z_matrix(file, map);
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
}
