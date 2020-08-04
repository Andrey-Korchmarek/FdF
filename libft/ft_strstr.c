/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:16:46 by mashley           #+#    #+#             */
/*   Updated: 2020/08/04 21:16:50 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystach, const char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystach);
	while (haystach[i])
	{
		j = 0;
		n = i;
		while (haystach[n] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystach[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}
