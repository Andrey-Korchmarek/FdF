/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:16:43 by mashley           #+#    #+#             */
/*   Updated: 2020/07/19 19:16:46 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_z_matrix(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**nums;
	char 	**parts;
	int		x;
	int		y;

	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (x < (*data).height)
	{
		get_next_line(fd, &line);
		(*data).z_matrix[x] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		(*data).color[x] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		if (nums)
			ft_free_matrix(&nums);
		nums = ft_strsplit(line, ' ');
		y = 0;
		while (y < (*data).width)
		{
			parts = ft_strsplit(nums[y], ',');
			(*data).z_matrix[x][y] = ft_atoi(parts[0]);
			(*data).color[x][y] = get_color(parts[1]);
			free(parts[0]);
			parts[0] = NULL;
			free(parts[1]);
			parts[1] = NULL;
			free(parts);
			parts = NULL;
			y++;
		}
		x++;
	}
	ft_free_matrix(&nums);
	free(line);
	line = NULL;
	close(fd);
	return ;
}
