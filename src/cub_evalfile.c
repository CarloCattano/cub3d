/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 12:09:39 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int		cub_evalfile(int fd, t_load *load)
{
	char *line;
	char **parts;
	
	ft_bzero(load);
	line = get_next_line(fd);
	while (line)
	{
		parts = ft_split(line, " ");
		if (!parts)
			return (close(fd), get_next_line(-2), cub_error(ERROR_MALOC, free, line));
		
		



	}
	return (close(fd), cub_error(ERROR_FILE_WRONG, NULL, NULL));
}


