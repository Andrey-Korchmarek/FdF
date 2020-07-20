/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spnbrcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:16:19 by mashley           #+#    #+#             */
/*   Updated: 2020/07/19 19:16:24 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_spnbrcount(char *str)
{
	int i;
	int count;

	i = 0;
	if (!(ft_isspace(str[i]) || ft_isnumber(str[i])))
		game_over(2);
	count = 0;
	while (str[i + 1])
	{
		if (ft_isspace(str[i]) && ft_isnumber(str[i + 1]))
			count++;
		else if (!(ft_isspace(str[i + 1]) || ft_isnumber(str[i + 1])))
			game_over(2);
		i++;
	}
	return (count);
}
