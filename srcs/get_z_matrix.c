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

static	void	get_z_color(char *line, int i, t_fdf *data)
{
	char	**nums;
	char	**str;
	int		j;

	nums = ft_strsplit(line, ' ');
	j = 0;
	while (j < (*data).width)
	{
		if (str)
			ft_free_matrix(&str);
		str = ft_strsplit(nums[j], ',');
		data->z_matrix[i][j] = ft_atoi(str[0]);
		data->color[i][j] = (str[1] ? ft_atoi_base(str[1] + 2, 16) : -1);
		j++;
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
	int		i;

	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (i < (*data).height)
	{
		get_next_line(fd, &line);
		data->z_matrix[i] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		data->color[i] = (int *)malloc(sizeof(int) * ((*data).width + 1));
		get_z_color(line, i, data);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	close(fd);
}
