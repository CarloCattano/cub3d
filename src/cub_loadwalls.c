/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:23:07 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/27 13:02:49 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* TODO:after load declare xoff and yoff must be done */
int	cub_loadwalls(t_load *l, t_sc *sc, void *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub_loadfile(&(sc->wall[i]), mlx, l->wall[i]))
			return (1);
		i++;
	}
	i = open(TD, O_RDONLY);
	if (i < 0)
		return (cub_error(E_SOTF, 2, NULL, NULL)); 
	close(i);
	if (cub_loadfile(&(sc->door), mlx, TD))
		return (1);
	return (0);
}
