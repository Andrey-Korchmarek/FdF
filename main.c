/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:12:28 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:12:59 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    fdf karta;

#ifdef TEST
    ft_putnbr(ft_strlen("Some error :("));
    ft_putchar(10);
    ft_putnbr(ft_strcount("0 0 0 0 0 0 0 0 0 0", ' '));
    ft_putchar(10);
#endif
    if (argc != 2)
    	game_over(1);
	karta = read_map(argv[1]);
#ifdef TEST
	int i = 0;
	int j;

	while (i < karta.height)
	{
		j = 0;
		while (j < karta.width)
		{
			ptintf("%3d", karta.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
#endif
    return (0);
}
