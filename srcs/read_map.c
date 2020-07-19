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

fdf	read_map(char *file)
{
    fdf		map;
    int 	*param;

    param = (int *)malloc(sizeof(int) * 3);
    param = get_height_and_width(file);
    map.height = param[0];
	map.width = param[1];
	map.z_matrix = (int **)malloc(sizeof(int*) * (map.height + 1));
	map = get_z_matrix(file, map);
	map.mlx_ptr = NULL;
	map.win_ptr = NULL;
	return (map);
}
