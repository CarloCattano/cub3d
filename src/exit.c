/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:16 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/26 20:47:28 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int mlx_terminate(t_cub *d)
{
	if (d->scr.img)
		mlx_destroy_image(d->mlx, d->scr.img);
	cub_freesc(&d->sc, d->mlx);
	if (d->win)
        mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	return (0);
}

