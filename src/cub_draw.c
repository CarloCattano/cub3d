/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:21:54 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/15 14:35:49 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* possible to give minimap */

int	cub_draw(t_cub *c)
{
	t_ray	*nray;
	//t_ray	*wray; // -> zoom rays for weapons etc

	nray = cub_ray(&(c->scene), c->screen.w,/* c->screen.fov*/ FOV);
	if (!nray)
		return (1);

/*	if (c->weapon.zoom)
		wray = cub_ray(&(c->scene), c->screen.w, c->weapon.fov);
	else	*/
	//wray = NULL;
	cub_draw_screen(c, nray);
	//cub_draw_sprites();
	/*
	cub_draw_weappon(c);*/
	cub_draw_minimap(c, nray);
	free(nray);
	return (0);
}


