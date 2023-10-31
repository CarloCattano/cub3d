/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_rs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:00:26 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 16:47:48 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

t_rpoint	*fdf_map_rs(int fd, t_win *win)
{
	t_rpoint	*data;
	char		*line;

	ft_printf("%s\n", IN_RMB);
	data = NULL;
	line = get_next_line(fd);
	while (line)
	{
		fdf_split(&fd, &data, win, line);
		gnl_free(&line);
		line = get_next_line(fd);
		if (line)
			win->ymax++;
	}
	return (data);
}
