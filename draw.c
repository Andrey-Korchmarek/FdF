#include "fdf.h"
#include "math.h"

//#define MAX1(a, b) (a > b ? a : b)
//#define MOD(a) ((a < 0) ? -a : a)

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z * 3;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	int color = (z || z1) ? 0xFFFF00 : 0xFFFFFF;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;
	t_dot	*start;
	t_dot	*end;

//	print_menu(*data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			start = get_dot(x, y, data);
			if (x < data->width)
			{
				end = get_dot(x +1, y, data);
				draw_line(start, end, data);
			}
			if (y < data->height)
			{
				end = get_dot(x, y + 1, data);
				draw_line(start, end, data);
			}
			x++;
		}
		y++;
	}
}
