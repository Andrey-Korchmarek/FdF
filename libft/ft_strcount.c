#include "libft.h"

int ft_strcount(const char *str, char chr)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == chr)
			count++;
		*str++;
	}
	return (count);
}