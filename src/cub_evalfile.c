/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		cub_evalfile(int fd, t_load *load)
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
			return (close(fd), get_next_line(-2), cub_error(E_MAL, free, line));
		if (parts[0])
			error = cub_evalline(fd, load, line, parts);
		gnl_free (&line);
		cub_dfree (&parts);	
		if (error == 2)
			return (close(fd), 0);
		if (error == 1)
			return (close(fd), get_next_line(-2), cub_error(E_FW, NULL, NULL));	
		line = get_next_line(fd);
	}
	return (close(fd), cub_error(E_FW, NULL, NULL));
}


