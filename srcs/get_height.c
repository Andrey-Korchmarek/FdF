#include "../fdf.h"

int	get_height(char *file)
{
	int     height;
	int		width;
	int     fd;
	char    *line;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	width = 0;
	while(get_next_line(fd, &line))
	{
		if (width && ft_strcount(line, ' ') != width)
			game_over(2);
		height++;
		width = ft_strcount(line, ' ');
		line = NULL;
		free(line);
	}
	close(fd);
	return (height);
}