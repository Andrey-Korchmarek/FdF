/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:11:24 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:11:31 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define TEST

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct	s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_dot;

t_fdf			read_map(char *file);
int				*get_height_and_width(char *file);
void			game_over(int error);
t_fdf			get_z_matrix(char *file, t_fdf data);
int				ft_spdgcount(char *str);

#endif
