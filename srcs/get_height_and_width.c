/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height_and_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:16:30 by mashley           #+#    #+#             */
/*   Updated: 2020/07/19 19:16:33 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height_and_width(char *file)
{
	static	int	param[3];
	int			fd;
	char		*line;

	if (param[0])
		return (param[1] + 1);
	fd = open(file, O_RDONLY, 0);
	param[0] = 0;
	param[1] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (param[1] != 0 && param[1] != ft_spnbrcount(line))
			game_over(4);
		param[0]++;
		param[1] = ft_spnbrcount(line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (param[0]);
}
