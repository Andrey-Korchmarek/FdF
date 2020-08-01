//
// Created by Akihiko Pearl on 7/12/20.
//

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct s_map
{
	int				**z_matrix;
	int				color;
}					t_map;

typedef struct
{
	int				width;
	int				height;
	int				**z_matrix;
	int				zoom;
	int				color;
	int				shift_x;
	int				shift_y;

	void			*mlx_ptr;
	void			*win_ptr;

	int				win_x;
	int				win_y;
	struct s_map	map;
}					fdf;

typedef struct	s_dot
{
	float			x;
	float			y;
	float			z;
	int				is_last;
	int				color;
	int				scale;
	int				z_scale;
	int				shift_x;
	int				shift_y;
	int				is_isometric;
	double			angle;
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_dot;

void				read_file(char *file_name, fdf *data);
void				bresenham(float x, float y, float x1, float y1, fdf *data);
void				draw(fdf *data);
int					mouse_press(int button, int x, int y, fdf *data);
void				print_menu(fdf txt);
int					deal_key(int button, fdf *data);
void				new_window(int key, fdf *data);
void				draw_line(t_dot start, t_dot end);

#endif