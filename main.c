//
// Created by Akihiko Pearl on 7/12/20.
//

#include "fdf.h"

int deal_key(int button, fdf *data)
{
//    printf("%d\n", button);
    if (button == 126)
        data->shift_y -= 10;
    if (button == 125)
        data->shift_y += 10;
    if (button == 123)
        data->shift_x -= 10;
    if (button == 124)
        data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

int		mouse_press(int button, int x, int y, fdf *data)
{
//    x++;
//    y++;
//    printf("%d\n", button);
    if (button == 1 || button == 2)
    {
        if (button == 2)
            data->shift_x  += 50;
        if (button == 1)
            if (data->shift_x  > 1)
                data->shift_x  -= 50;
    }
    if (button == 4 || button == 5)
    {
        if (button == 4)
            data->shift_y  += 50;
        if (button == 5)
            if (data->shift_y  > 1)
                data->shift_y  -= 50;
    }
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
    mlx_mouse_hook(data->win_ptr, mouse_press, data);
    mlx_loop(data->mlx_ptr);
}
