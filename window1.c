////
//// Created by Akihiko Pearl on 7/19/20.
////
//
//#include "fdf.h"
//
//int		check_win_size(int key, fdf **z_matrix)
//{
//    if ((key == 0 && ZM.win_y <= 500) || (key == 6 && ZM.win_x <= 500))
//        return (1);
//    if ((key == 1 && ZM.win_y > 1000) || (key == 7 && ZM.win_x > 2000))
//        return (1);
//    return (0);
//}
//
//void	full_screen(fdf **z_matrix)
//{
//    static int old_x;
//    static int old_y;
//
//    if (ZM.win_x != 2560)
//    {
//        old_x = ZM.win_x;
//        old_y = ZM.win_y;
//    }
//    ZM.win_x = (ZM.win_x == 2560) ? old_x : 2560;
//    ZM.win_y = (ZM.win_y == 1400) ? old_y : 1400;
//}
//
//void	change_window_size(int key, fdf **z_matrix)
//{
//    if (check_win_size(key, z_matrix))
//        return ;
//    if (key == 6)
//        ZM.win_x -= 100;
//    if (key == 7)
//        ZM.win_x += 100;
//    if (key == 0)
//        ZM.win_y -= 100;
//    if (key == 1)
//        ZM.win_y += 100;
//    if (key == 3)
//        full_screen(z_matrix);
//}
//void	new_window(int key, fdf **z_matrix)
//{
//    change_window_size(key, z_matrix);
//    mlx_destroy_window(ZM.mlx_ptr, ZM.win_ptr);
//    ZM.mlx_ptr = mlx_init();
//    ZM.win_ptr = mlx_new_window(ZM.mlx_ptr, ZM.win_x, ZM.win_y, "FDF");
//    ZM.shift_x = ZM.win_x / 3;
//    ZM.shift_y = ZM.win_y / 3;
//    draw(*z_matrix);
//    mlx_key_hook(ZM.win_ptr, deal_key, z_matrix);
//    mlx_loop(ZM.mlx_ptr);
//}
