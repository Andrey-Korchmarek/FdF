//
// Created by Akihiko Pearl on 7/12/20.
//

#ifndef FDF_H
# define FDF_H
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct
{
    int width;
    int height;
    int **z_matrix;

    void *mlx_ptr;
    void *win_ptr;
}           fdf;

void read_file(char *file_name, fdf *data);

#endif