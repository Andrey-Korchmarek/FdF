/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:43:20 by mashley           #+#    #+#             */
/*   Updated: 2020/07/18 16:43:24 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	game_over(int error)
{
	if (error == 0)
		ft_putstr("Error!!");
	else if (error == 1)
		ft_putstr("Invalid arguments!");
	else if (error == 2)
		ft_putstr("Invalid file");
	else if (error == 3)
		ft_putstr("3");
	else if (error == 4)
		ft_putstr("4");
	else if (error == 5)
		ft_putstr("5Q");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else
		ft_putstr("Some error :(");
	exit(0);
}
