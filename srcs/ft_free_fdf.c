/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:02:06 by mashley           #+#    #+#             */
/*   Updated: 2020/07/23 12:02:13 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_fdf(t_fdf *data)
{
	int i;

	i = 0;
	while (((*data).z_matrix)[i])
	{
		free(((*data).z_matrix)[i]);
		((*data).z_matrix)[i] = NULL;
		i++;
	}
	free((*data).z_matrix);
	(*data).z_matrix = NULL;
	while (((*data).color)[i])
	{
		free(((*data).color)[i]);
		((*data).color)[i] = NULL;
		i++;
	}
	free((*data).color);
	(*data).color = NULL;
	free(data);
	data = NULL;
	return ;
}
