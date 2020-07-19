//
// Created by Akihiko Pearl on 7/19/20.
//

#include "fdf.h"

void	print_menu(fdf txt) {
    char *str;

    str = "mouse  click -> right left; -> scroll up down: move the map";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 1000, 0x00FF00, str);
    str = "keyboard -> right left, up, down: move the map";
    mlx_string_put(txt.mlx_ptr, txt.win_ptr, 15, 1025, 0x00FFFF, str);
}
