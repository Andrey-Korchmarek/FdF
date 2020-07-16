#include "../fdf.h"

void game_over(int error)
{
	if (error == 0)
		write(0, "Error!!", 7);
	exit(0);
	return ;
}