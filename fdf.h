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
# include "minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int 		**color;
	int zoom;
	int shift_x;
	int shift_y;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;

	int			is_last;
	int			scale;
	int			z_scale;
	int			is_isometric;
	double		angle;

}				t_fdf;

typedef struct	s_dot
{
	float		x;
	float		y;
	float		z;
	int			color;


}				t_dot;

void			read_map(char *file, t_fdf *map);
int				get_height_and_width(char *file);
void			game_over(int error);
void			get_z_matrix(char *file, t_fdf *data);
int				ft_spnbrcount(char *str);
void			ft_free_fdf(t_fdf *data);
void			set_default(t_fdf *data);
void			bresenham(float x, float y, float x1, float y1, t_fdf karta);
void			draw(t_fdf karta);
void			isometric(float *x, float *y, int z);
void			print_menu(t_fdf txt);

#endif
