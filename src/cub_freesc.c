/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freesc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:58:32 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 20:03:53 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_ftn(t_sc *sc, vod *mlx, int i)
{
		i = -1;
		while (++i < 9)
		{
			if (sc->ply->sprites[i].img)
			{	
				mlx_destroy_image(mlx, sc->ply->sprites[i].img->img);
				free(sc->ply->sprites[i].img);
			}
		}
		free(sc->ply.sprites);
}

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
	if (sc->ply.sprites)
	{
		ft_ftn(sc, malx, i);
	}
	if (sc->sprites)
		free(sc->sprites);
	if (sc->extra)
		free(sc->extra);
}
