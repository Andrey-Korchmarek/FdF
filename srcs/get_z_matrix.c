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

	nums = NULL;
	parts = NULL;
	line = NULL;
	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (get_next_line(fd, &line) == 1)
	{
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
			if (parts[0])
			{
				free(parts[0]);
				parts[0] = NULL;
			}
			if (parts[1])
			{
				free(parts[1]);
				parts[1] = NULL;
			}
			if (parts)
			{
				free(parts);
				parts = NULL;
			}
			y++;
		}
		ft_strdel(&line);
		x++;
	}
	ft_free_matrix(&nums);
	free(line);
	line = NULL;
	close(fd);
	(*data).win_ptr = NULL;
	(*data).mlx_ptr = NULL;
	return ;
}
