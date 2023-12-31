/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:50:31 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_norm(char er, char *msg, void (*f)(), void *ptr)
{
	get_next_line(-2);
	return (cub_error(msg, er, f, ptr));
}

int	cub_evalfile(int fd, t_load *load)
{
	char	*line;
	char	**parts;
	int		error;

	ft_bzero(load, sizeof(t_load));
	line = get_next_line(fd);
	while (line)
	{
		error = 0;
		parts = cub_splits(line, " \n");
		if (!parts)
			return (close(fd), ft_norm(1, E_MAL, free, line));
		if (parts[0])
			error = cub_evalline(fd, load, line, parts);
		gnl_free (&line);
		cub_dfree (&parts);
		if (error == 2)
			return (close(fd), 0);
		if (error == 1)
			return (close(fd), ft_norm(0, E_FC, NULL, NULL));
		line = get_next_line(fd);
	}
	return (close(fd), cub_error(E_FC, 1, NULL, NULL));
}
