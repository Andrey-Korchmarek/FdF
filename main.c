//
// Created by Akihiko Pearl on 7/12/20.
//

#include "fdf.h"

int deal_key(int button, fdf *data)
{
//    printf("%d\n", button);
    if (button == 126) // up button
        data->shift_y -= 10;
    if (button == 125) // down
        data->shift_y += 10;
    if (button == 123) // left
        data->shift_x -= 10;
    if (button == 124) // right
        data->shift_x += 10;
    if (button == 3) // letter F
        new_window(button, data);
    if (button == 69 || button == 78 || button == 67 || button == 75) //  + - * / from numpad of keyboard
        new_window(button, data);
    if (button == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        free(data);
        exit(0);
    }
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
    if (button == 3)  //  F
        new_window(button, data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

void	set_default(fdf *data)
{
    data->zoom = 20;
//    param->z_scale = 1;
//    param->is_isometric = 1;
//    param->angle = 0.523599;
    data->win_x = 2000;
    data->win_y = 1000;
    data->shift_x = data->win_x / 3;
    data->shift_y = data->win_y / 3;
    data->mlx_ptr = mlx_init();
    data->win_ptr =\
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}
int main(int argc, char **argv)
{
    fdf *data;

    if (argc != 2)
    {
        char *txt;
        txt = "Use this command: ./fdf testmap.fdf";
        ft_printf("%s\n", txt );
        return (0);
    }
    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    set_default(data);
//    data->mlx_ptr = mlx_init();
//   data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1200, "FDF");
//    data->zoom = 20;
//    bresenham(10, 10, 500, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_mouse_hook(data->win_ptr, mouse_press, data);
    mlx_loop(data->mlx_ptr);
}
