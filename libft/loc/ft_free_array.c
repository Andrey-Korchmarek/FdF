#include "libft.h"

void	ft_free_array(int ***as)
{
	int i;

	if (!as || !(*as))
		return ;
	i = 0;
	while (*as[i])
	{
		free(*as[i]);
		*as[i] = NULL;
		i++;
	}
	free(*as);
	*as = NULL;
}