#include "../fdf.h"

int	*get_height_and_width(char *file)
{
	int 	param[2];
	int     fd;
	char    *line;

	fd = open(file, O_RDONLY, 0);
	param[0] = 0;
	param[1] = 0;
	while(get_next_line(fd, &line))
	{
		if (param[1] != 0 && ft_spdgcount(line) != param[1])
			game_over(2);
		param[0]++;
		param[1] = ft_spdgcount(line);
		line = NULL;
		free(line);
	}
	close(fd);
	return (param);
}