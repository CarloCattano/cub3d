/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:05:03 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 17:51:27 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/* get .fdf file and open check and store data if possible*/
void	fdf_load_map(char *map, t_fdf *fdf)
{
	int	fd;	

	fdf_init_window(&fdf->win);
	ft_printf("%s\n", TXT_BE);
	fd = open(map, O_RDONLY);
	if (fd < 3)
	{
		if (fd < 0)
			fdf_exit_error(ERR_OPEN, 1);
		fdf_exit_error(ERR_OPEN, 0);
	}
	fdf->store = fdf_map_rss(fd, &fdf->win);
	fd = close(fd);
	if (fd < 0)
	{
		if (fdf->store)
			free(fdf->store);
		fdf_exit_error(ERR_CLOSE, 1);
	}
	ft_printf("%s\n", TXT_EN);
}
