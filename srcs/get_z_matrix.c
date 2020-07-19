#include "../fdf.h"

fdf get_z_matrix(char *file, fdf data)
{
	int 	fd;
	char 	*line;
	char	**nums;
	int 	x;
	int 	y;

	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (x < data.height)
	{
		get_next_line(fd, &line);
		data.z_matrix[x] = (int *)malloc(sizeof(int) * (data.width + 1));
		nums = ft_strsplit(line, ' ');
		y = 0;
		while (y < data.width)
		{
			data.z_matrix[x][y] = ft_atoi(nums[y]);
			y++;
		}
		line = NULL;
		x++;
	}
	line = NULL;
	free(line);
	close(fd);
	return (data);
}