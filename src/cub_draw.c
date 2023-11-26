/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:21:54 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:46:56 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	if (c->wp.zoom)
	wray = cub_ray(&(c->sc), c->scr.w, c->wp.fov);
else	*/
/* wray = NULL; */
/* t_ray	*wray; // -> zoom rays for wps etc */
/* nray = cub_ray(&(c->sc), c->scr.w,/1* c->scr.fov) */

int	cub_draw(t_cub *c)
{
	t_ray	*nray;

	nray = cub_ray(&(c->sc), c->scr.w, FOV);
	if (!nray)
		return (1);
	cub_draw_screen(c, nray);
	if (c->bonus == 1)
		cub_draw_minimap(c, nray);
	mlx_put_image_to_window(c->mlx, c->win, c->scr.img, 0, 0);
	handle_ply(c);
	draw_wp(c);
	free(nray);
	return (0);
}
