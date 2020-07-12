//
// Created by Akihiko Pearl on 7/12/20.
//

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int deal_key(int key, fdf *data)
{
    printf("%d\n", key);
    return (0);
}

int main(int argc, char **argv)
{
    fdf *data;

    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, "FDF");
    data->zoom = 20;
//    bresenham(10, 10, 500, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
}

//gcc *.c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit