#include "../fdf.h"

int	get_height(char *file)
{
	int     height;
	int     fd;
	char    *line;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		line = NULL;
		free(line);
	}
	close(fd);
	return (height);
}