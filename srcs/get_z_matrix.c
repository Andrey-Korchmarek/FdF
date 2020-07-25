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
<<<<<<< HEAD
//		ft_free_matrix(&nums);
		x++;
	}
//	ft_strdel(&line);
=======
		x++;
	}
	free(line);
	line = NULL;
	x = 0;
	while (nums[x])
	{
		free(nums[x]);
		nums[x] = NULL;
		x++;
	}
	free(nums);
	nums = NULL;
>>>>>>> 85a04fc2200002a6cfea480b0046465653b2f218
	close(fd);
	return ;
}
