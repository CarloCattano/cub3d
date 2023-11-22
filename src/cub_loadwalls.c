/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:23:07 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:17:31 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* TODO:after load declare xoff and yoff must be done */
int	cub_loadwalls(t_load *l, t_sc *sc, void *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub_loadfile(&(sc->wall[i]), mlx, l->wall[i]))
			return(1);
		i++;
	}
	return (0);
}
