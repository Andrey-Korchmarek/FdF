//
// Created by Akihiko Pearl on 7/12/20.
//

#include "fdf.h"

//int deal_key(int key, fdf *data)
//{
//    printf("%d\n", key);
//    if (key == 3)
//        data->shift_y -= 10;
//    if (key == 4)
//        data->shift_y += 10;
//    if (key == 1)
//        data->shift_x -= 10;
//    if (key == 2)
//        data->shift_x += 10;
//    mlx_clear_window(data->mlx_ptr, data->win_ptr);
//    draw(data);
//
//    return (0);
//}
int deal_key(int key, fdf *data)
{
    printf("%d\n", key);
    if (key == 126)
        data->shift_y -= 10;
    if (key == 125)
        data->shift_y += 10;
    if (key == 123)
        data->shift_x -= 10;
    if (key == 124)
        data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}
int main(int argc, char **argv)
{
    fdf *data;

    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1200, "FDF");
    data->zoom = 20;
//    bresenham(10, 10, 500, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);

//    mlx_mouse_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
}

//gcc *.c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
//int
//mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
//
//int
//mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

//left click = 1
//right click = 2
//center click = 3
//down scroll = 4
//up scroll = 5
