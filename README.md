
gcc *.c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

./a.out test_maps/42.fdf 

int
mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
When  it catches an event, the MiniLibX calls the corresponding function with fixed
parameters:

expose_hook(void *param);
key_hook(int keycode,void *param);
mouse_hook(int button,int x,int y,void *param);
loop_hook(void *param);

left click = 1
right click = 2
center click = 3
down scroll = 4
up scroll = 5

https://github.com/nikGrape/FDF

Subjects:
https://projects.intra.42.fr/fdf/mine

https://github.com/HalimHamidov/fdf

https://github.com/Andrey-Korchmarek/FdF

https://github.com/nikGrape/FDF

https://www.youtube.com/watch?v=10P59aOgi68

https://github.com/VBrazhnik/FdF/wiki/How-to-perform-isometric-transformations%3F


elearning video script upload
https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events

https://github.com/qst0/ft_libgfx



plan:
1. nikGrape's work commit by commit download and checking!

2. https://github.com/pbondoer/42-FdF commit's

https://github.com/mamedzavr/FdF/tree/master/srcs

http://tmaplatform.ru/page/help/api/imagefield/!color