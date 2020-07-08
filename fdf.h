/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:11:24 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:11:31 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "minilibx_macos/mlx_int.h"
#include "minilibx_macos/mlx_new_window.h"

typedef struct
{
    int     width;
    int     height;
    int     **z_matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;

void    read_map(char *file);

#endif
