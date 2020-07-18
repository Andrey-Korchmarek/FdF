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

    map.height = get_height(file);
	map.width = get_width(file);
	map.z_matrix = (int **)malloc(sizeof(int*) * (map.height + 1));
	get_z_matrix(file, &map);
	map.mlx_ptr = NULL;
	map.win_ptr = NULL;
	return (map);
}
