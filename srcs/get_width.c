#include "../fdf.h"

int get_width(char *file)
{
	int width;
	int fd;
	char *line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_strcount(line, ' ');
	line = NULL;
	free(line);
	close(fd);
	return (width);
}