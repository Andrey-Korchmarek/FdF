#include "../fdf.h"

int	ft_spdgcount(char *str)
{
	int i;
	int count;

	i = 0;
	if (!(ft_isspace(str[i]) || ft_isdigit2(str[i])))
		game_over(2);
	count = 0;
	while (str[i + 1])
	{
		if (ft_isspace(str[i]) && ft_isdigit2(str[i + 1]))
			count++;
		else if (!(ft_isspace(str[i + 1]) || ft_isdigit2(str[i + 1])))
			game_over(2);
		i++;
	}
	return (count);
}