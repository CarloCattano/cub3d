/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:22:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 17:50:33 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_ply(t_cub *d)
{
	d->sc.ply.movespeed = MOVE_SPEED;
	d->sc.ply.ctrl.up_down = 0;
	d->sc.ply.ctrl.left_right = 0;
	d->sc.ply.ctrl.turn = 0;
	d->sc.ply.lastX = WIDTH >> 1;
	d->sc.ply.rotSpeed = ROT_S;
	d->sc.ply.wp_s = 1.0f;
}

int	cub_init(t_cub *c, t_sc *sc)
{
	c->sc = *sc;
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3D");
	c->scr.img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->scr.pix = mlx_get_data_addr(c->scr.img, &c->scr.bpp, &c->scr.ll, &c->scr.endian);	
	c->scr.h = HEIGHT;
	c->scr.w = WIDTH; 	
	c->mini.h = MHEIGHT;
	c->mini.w = MWIDTH;	
	c->mini.xoff = MWIDTH / (double)(c->sc.map.width);
    c->mini.yoff = MHEIGHT / (double)(c->sc.map.height);
	c->mini.wxoff = 5;
	c->mini.wyoff = 5;
	ft_init_ply(c);	
	return (0);
}	

