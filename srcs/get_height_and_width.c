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

int	get_height_and_width(char *file, int key)
{
	int		param[3];
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	param[0] = 0;
	param[1] = 0;
	param[2] = 1;
	while (param[2] == 1)
	{
//		if (line)
//		{
//			free(line);
//			line = NULL;
//		}
		param[2] = get_next_line(fd, &line);
		if (param[1] != 0 && (param[1] != ft_spnbrcount(line)))
			game_over(4);
		param[0]++;
		param[1] = ft_spnbrcount(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
	if (key)
		return (param[1] + 1);
	return (param[0]);
}
