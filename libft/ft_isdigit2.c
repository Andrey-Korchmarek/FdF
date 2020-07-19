#include "libft.h"

int	ft_isdigit2(int c)
{
	return (ft_issign(c) || ft_isdigit(c));
}