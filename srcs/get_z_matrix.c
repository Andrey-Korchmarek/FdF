#include "../fdf.h"

void get_z_matrix(char *file, fdf *data)
{
	int fd;
	int x;
	int y;

	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (x < *data->height)
	{
		y = 0;
		while (y < *data->width)
		{
			*data->z_matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	close(fd);
	return ;
}