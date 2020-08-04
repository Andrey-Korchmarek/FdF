/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:25:09 by mashley           #+#    #+#             */
/*   Updated: 2020/08/02 17:25:20 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TEST
#include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef	struct		s_fdf
{
	int				width;
	int				height;
	int				**z_matrix;
	int				**color;
	int				zoom;
	int				shift_x;
	int				shift_y;
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;

	int				is_last;
	int				scale;
	int				z_scale;
	int				is_isometric;
	double			angle;

}					t_fdf;

typedef struct		s_dot
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_dot;

void				draw(t_fdf *data);
int					mouse_press(int button, int x, int y, t_fdf *data);
void				print_menu(t_fdf txt);
int					deal_key(int button, t_fdf *data);
void				new_window(int key, t_fdf *data);
void				isometric(t_dot *start, t_dot *end, t_fdf *data);

void				draw_line(t_dot *start, t_dot *end, t_fdf *data);
t_dot				*get_dot(int x, int y, t_fdf *data);
void				read_map(char *file, t_fdf *map);
void				get_z_matrix(char *file, t_fdf *data);
int					get_height_and_width(char *file);
int					ft_spnbrcount(char *str);
void				game_over(int error);
void				ft_free_fdf(t_fdf *data);
int 				get_color(t_dot *start, t_dot *end);
void				zoom(t_dot *start, t_dot *end, t_fdf *data);

#endif
