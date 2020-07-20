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

int	*get_height_and_width(char *file)
{
	int		param[2];
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	param[0] = 0;
	param[1] = 0;
	while (get_next_line(fd, &line))
	{
//		ft_putnbr(ft_spnbrcount(line));
//		ft_putchar(' ');
//		ft_putnbr(param[1]);
//		ft_putchar(10);
		if (param[1] != 0 && ft_spnbrcount(line) != param[1])
			game_over(2);
		param[0]++;
		param[1] = ft_spnbrcount(line);
		line = NULL;
		free(line);
	}
	line = NULL;
	free(line);
	close(fd);
	return (param);
}
