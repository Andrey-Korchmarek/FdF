#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "math.h"

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct
{
	int			width;
	int			height;
	int			**z_matrix;
	int			**color;
	int			zoom;
	int			shift_x;
	int			shift_y;
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
void			isometric(float *x, float *y, int z);
void			print_menu(t_fdf txt);
void			read_file(char *file_name, t_fdf *data);
void			bresenham(float x, float y, float x1, float y1, t_fdf *data);
void			draw(t_fdf *data);
int				mouse_press(int button, t_fdf *data);
int				deal_key(int button, t_fdf *data);
void			new_window(int key, t_fdf *data);
void			change_window_size(int key, t_fdf *data);
int				check_win_size(int key, t_fdf *data);

#endif
