
#include "../fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void isometric(float *x, float *y, int z)
{
//    *x = (*x - *y) * cos(0.8);
//   *y = (*x + *y) * sin(0.8) - z;
    *x = (*x - *y) * cos(0.523599);
    *y = (*x + *y) * sin(0.523599) - z;

}
void bresenham(float x, float y, float x1, float y1, t_fdf karta)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = karta.z_matrix[(int)y][(int)x];
    z1 = karta.z_matrix[(int)y1][(int)x1];

    x *= karta.zoom;
    y *= karta.zoom;
    x1 *= karta.zoom;
    y1 *= karta.zoom;


    karta.color[(int)y][(int)x] = z ? 0xFFFF00 : 0xFFFFFF;
	karta.color[(int)y1][(int)x1] = z1 ? 0xFFFF00 : 0xFFFFFF;

    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);

    x += karta.shift_x;
    y += karta.shift_y;
    x1 += karta.shift_x;
    y1 += karta.shift_y;

    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y-y1))
    {
        mlx_pixel_put(karta.mlx_ptr, karta.win_ptr, x, y, karta.color[(int)y][(int)x]);
        x += x_step;
        y += y_step;
    }
}

void draw(t_fdf karta)
{
    int x;
    int y;

    print_menu(karta);
    y = 0;
    while (y < karta.height)
    {
        x = 0;
        while (x < karta.width)
        {
            if (x < karta.width - 1)
                bresenham(x, y, x + 1, y, karta);
            if (y < karta.height - 1)
                bresenham(x, y, x, y + 1, karta);
            x++;
        }
        y++;
    }
}