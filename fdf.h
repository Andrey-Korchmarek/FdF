//
// Created by Akihiko Pearl on 7/12/20.
//

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;
    int			color1;
    int			color2;
    int			color3;

    void *mlx_ptr;
    void *win_ptr;
}           fdf;

void read_file(char *file_name, fdf *data);
void bresenham(float x, float y, float x1, float y1, fdf *data);
void draw(fdf *data);
int				mouse_press(int button, int x, int y, fdf *data);
int				change_colorset(fdf *data, int colorset);
int				multicolor_display(fdf *data);
int				draw_buttons(fdf *data);
#endif