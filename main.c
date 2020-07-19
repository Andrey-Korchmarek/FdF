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

int	main(int argc, char **argv)
{
	t_fdf	karta;
#ifdef TEST
	int i;
	int j;
#endif

	if (argc != 2)
		game_over(1);
	karta = read_map(argv[1]);
#ifdef TEST
	i = 0;
	while (i < karta.height)
	{
		j = 0;
		while (j < karta.width)
		{
			printf("%3d", karta.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
#endif
	return (0);
}
