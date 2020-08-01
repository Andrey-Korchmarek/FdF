#include "../fdf.h"

void	set_default(t_fdf *data)
{
	data->zoom = 20;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
}
