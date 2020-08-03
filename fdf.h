/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:51:05 by mashley           #+#    #+#             */
/*   Updated: 2020/08/03 17:51:10 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TEST
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "math.h"
# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		win_x;
	int		win_y;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void		read_file(char *file_name, fdf *data);
void		bresenham(float x, float y, float x1, float y1, fdf *data);
void		draw(fdf *data);
int			mouse_press(int button, fdf *data);
void		print_menu(fdf txt);
int			deal_key(int button, fdf *data);
void		new_window(int key, fdf *data);

#endif
