/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:28:06 by mashley           #+#    #+#             */
/*   Updated: 2020/07/08 14:28:10 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void    read_map(char *file)
{
    int     n;
    int     fd;
    char    **line;

    fd = open(file, O_RDONLY);
    n = get_next_line(fd, line);
    close(fd);
    return ;
}
