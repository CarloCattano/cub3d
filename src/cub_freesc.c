/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freesc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:58:32 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:55:23 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*TODO freesc has also to free mlx and dteroy display */
void	cub_freesc(t_sc *sc, void *mlx)
{
	int	i;

	if (sc->floor)
		mlx_destroy_image(mlx, sc->floor->img);
	if (sc->ceiling)
		mlx_destroy_image(mlx, sc->ceiling->img);
	i = -1;
	while (++i < 4)
	{
		if (sc->wall[i].img)
			mlx_destroy_image(mlx, sc->wall[i].img);
	}
	cub_dfree(&(sc->map.val));
}
