#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "math.h"

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef	struct		s_map
{
	int				**z_matrix;
	int				color;
}					t_map;

typedef	struct		s_fdf
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
}					t_fdf;

typedef struct		s_dot
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

void				read_file(char *file_name, t_fdf *data);
void				bresenham(float x, float y, float x1,
						float y1, t_fdf *data);
void				draw(t_fdf *data);
int					mouse_press(int button, int x, int y, t_fdf *data);
void				print_menu(t_fdf txt);
int					deal_key(int button, t_fdf *data);
void				new_window(int key, t_fdf *data);
void				draw_line(t_dot start, t_dot end);

#endif
