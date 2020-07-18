#include "fdf.h"

static int	draw_colorset_buttons(fdf *data, int x, int y)
{
    int		x_save;
    int		color;

    x_save = x;
    if (x == 20)
        color = 0xFFFFFF;
    else if (x == 70)
        color = 0x00FF00;
    else if (x == 120)
        color = 0x0038FF;
    else
        color = 0x660099;
    while (y < 50)
    {
        x = x_save;
        while (x < (x_save + 40))
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
            x++;
        }
        y++;
    }
    return (0);
}

int			draw_buttons(fdf *data)
{
    int	x;
    int	y;

    x = 20;
    y = 20;
    while (x <= 170)
    {
        draw_colorset_buttons(data, x, y);
        x += 50;
    }
    return (0);
}

int			multicolor_display(fdf *data)
{
    static int	color = 0;

    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    data->color1 = color;
    data->color2 = color;
    data->color3 = color;
    draw(data);
    color += 2099648;
    return (0);
}

int			change_colorset(fdf *data, int colorset)
{
    if (colorset == 0)
    {
        data->color1 = 0xFFFFFF;
        data->color2 = data->color1;
        data->color3 = data->color1;
    }
    else if (colorset == 1)
    {
        data->color1 = 0x00FF00;
        data->color2 = 0xFF0000;
        data->color3 = 0xFFFF00;
    }
    else if (colorset == 2)
    {
        data->color1 = 0x0038FF;
        data->color2 = 0x00A433;
        data->color3 = 0x562B00;
    }
    else if (colorset == 3)
    {
        data->color1 = 0x660099;
        data->color2 = 0x336699;
        data->color3 = 0x000000;
    }
    return (0);
}