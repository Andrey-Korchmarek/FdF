/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:16:38 by mashley           #+#    #+#             */
/*   Updated: 2020/07/19 19:16:41 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_spnbrcount(line);
	free(line);
	line = NULL;
	close(fd);
	return (width + 1);
}
