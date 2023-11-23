/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:21:54 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/23 22:23:04 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_draw(t_cub *c)
{
	t_ray	*nray;
	//t_ray	*wray; // -> zoom rays for wps etc

	nray = cub_ray(&(c->sc), c->scr.w,/* c->scr.fov*/ FOV);
	if (!nray)
		return (1);

	/*	if (c->wp.zoom)
		wray = cub_ray(&(c->sc), c->scr.w, c->wp.fov);
	else	*/
	//wray = NULL;
	cub_draw_screen(c, nray);
	//cub_draw_sprites();
	if (c->bonus == 1)
		cub_draw_minimap(c, nray);
	handle_ply(c);
	draw_wp(c);
	free(nray);
	return (0);
}

