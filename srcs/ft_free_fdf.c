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
<<<<<<< HEAD
	while (((*data).z_matrix)[i])
	{
		free(((*data).z_matrix)[i]);
		((*data).z_matrix)[i] = NULL;
=======
	while ((*data).z_matrix[i])
	{
		free((*data).z_matrix[i]);
		(*data).z_matrix[i] = NULL;
>>>>>>> 85a04fc2200002a6cfea480b0046465653b2f218
		i++;
	}
	free((*data).z_matrix);
	(*data).z_matrix = NULL;
<<<<<<< HEAD
	while (((*data).color)[i])
	{
		free(((*data).color)[i]);
		((*data).color)[i] = NULL;
=======
	while ((*data).color[i])
	{
		free((*data).color[i]);
		(*data).color[i] = NULL;
>>>>>>> 85a04fc2200002a6cfea480b0046465653b2f218
		i++;
	}
	free((*data).color);
	(*data).color = NULL;
	free(data);
	data = NULL;
	return ;
}
