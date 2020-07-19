#include "../fdf.h"

fdf get_z_matrix(char *file, fdf data)
{
	int fd;
	int x;
	int y;

	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (x < data.height)
	{
		data.z_matrix[x] = (int *)malloc(sizeof(int) * (data.width + 1));
		y = 0;
		while (y < data.width)
		{
			data.z_matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	close(fd);
	return (data);
}