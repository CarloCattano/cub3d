/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:22:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:17:31 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cub_init(t_cub *c, t_sc *sc)
{
	c->sc = *sc;
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3d");
	c->screen.img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->screen.pix = mlx_get_data_addr(c->screen.img, &c->screen.bpp, &c->screen.ll, &c->screen.endian);	
	c->screen.h = HEIGHT;
	c->screen.w = WIDTH; 	
	c->mini.img = mlx_new_image(c->mlx, MWIDTH, MHEIGHT);
	c->mini.pix = mlx_get_data_addr(c->mini.img, &c->mini.bpp, &c->mini.ll, &c->mini.endian);	
	c->mini.h = MHEIGHT;
	c->mini.w = MWIDTH;	
	return (0);
}	


