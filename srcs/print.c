//
// Created by Akihiko Pearl on 7/19/20.
//

#include "../fdf.h"

void	print_menu(t_fdf txt)
{
    char *str;

    str = "keyboard -> button 'ESC': exit and force quit the mlx window";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 25, 0xFF0000, str);//red
    str = "mouse  click -> right left; -> scroll up down: move the map";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 50, 0x00FF00, str);//green
    str = "keyboard -> right left, up, down: move the map";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 75, 0x00FFFF, str);//blue
    str = "keyboard -> button 'F': toggle fullscreen and default";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 100, 0xFFFFFF, str); // white
    str = "keyboard numpad-> buttons + - * / resp.: right-extend; left-shrink; up-extend; down-shrink mlx-window";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 125, 0xFFFF00, str);//yellow
}
