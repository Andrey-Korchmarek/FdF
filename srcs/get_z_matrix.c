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

static	void	get_z_color(char *line, int x, t_fdf *data)
{
	char	**nums;
	char	**str;
	int		y;

	nums = ft_strsplit(line, ' ');
	y = 0;
	while (y < (*data).width)
	{
		if (str)
			ft_free_matrix(&str);
		str = ft_strsplit(nums[y], ',');
		data->z_matrix[x][y] = ft_atoi(str[0]);
		data->color[x][y] = (str[1] ? ft_atoi_base(str[1] + 2, 16) : -1);
		y++;
	}
	if (str)
		ft_free_matrix(&str);
	if (nums)
		ft_free_matrix(&nums);
}

void			get_z_matrix(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(file, O_RDONLY, 0);
	x = 0;
	while (x < (*data).height)
	{
		get_next_line(fd, &line);
		data->z_matrix[x] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		data->color[x] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		get_z_color(line, x, data);
		ft_strdel(&line);
		x++;
	}
	ft_strdel(&line);
	close(fd);
}
