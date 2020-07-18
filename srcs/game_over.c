#include "../fdf.h"

void game_over(int error)
{
	if (error == 0)
		write(0, "Error!!", 7);
	else if (error == 1)
		write(0, "Invalid arguments!", 18);
	else if (error == 32)
		write(0, "!", 1);
	else
		write(0, "Some error :(", 1);
	exit(0);
	return ;
}