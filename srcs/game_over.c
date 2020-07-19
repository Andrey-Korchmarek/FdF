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

#include "../fdf.h"

void	game_over(int error)
{
	if (error == 0)
		write(0, "Error!!", 7);
	else if (error == 1)
		write(0, "Invalid arguments!", 18);
	else if (error == 2)
		write(0, "Invalid file", 12);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else if (error == 32)
		write(0, "!", 1);
	else
		write(0, "Some error :(", 13);
	exit(0);
}
