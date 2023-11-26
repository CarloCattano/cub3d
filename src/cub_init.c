/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:22:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:23:38 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_wp_sprites(t_cub *c)
{
	char	*paths[9];
	int		i;

	paths[0] = "./res/gun/gun.xpm";
	paths[1] = "./res/gun/gun1.xpm";
	paths[2] = "./res/gun/gun2.xpm";
	paths[3] = "./res/gun/gun3.xpm";
	paths[4] = "./res/gun/gun4.xpm";
	paths[5] = "./res/gun/gun5.xpm";
	paths[6] = "./res/gun/gun6.xpm";
	paths[7] = "./res/gun/gun7.xpm";
	paths[8] = "./res/gun/gun8.xpm";
	i = -1;
	while (++i < 9)
	{
		c->sc.ply.sprites[i].path = paths[i];
		c->sc.ply.sprites[i].img = malloc(sizeof(t_image));
		c->sc.ply.sprites[i].img->img = mlx_xpm_file_to_image(c->mlx,
				c->sc.ply.sprites[i].path, &c->sc.ply.sprites[i].img->w,
				&c->sc.ply.sprites[i].img->h);
		c->sc.ply.sprites[i].img->pix = mlx_get_data_addr(
				c->sc.ply.sprites[i].img->img, &c->sc.ply.sprites[i].img->bpp,
				&c->sc.ply.sprites[i].img->ll,
				&c->sc.ply.sprites[i].img->endian);
	}
	return (0);
}

static int	ft_init_wp(t_cub *d)
{
   // TODO not needed , default weapon state is sprite[0]
	/* d->sc.ply.wp.path = "./res/gun/gun.xpm"; */
	/* d->sc.ply.wp.img.img = mlx_xpm_file_to_image(d->mlx, d->sc.ply.wp.path, */
	/* 		&d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h); */
	/* d->sc.ply.wp.img.pix = mlx_get_data_addr(d->sc.ply.wp.img.img, */
	/* 		&d->sc.ply.wp.img.bpp, &d->sc.ply.wp.img.ll, */
	/* 		&d->sc.ply.wp.img.endian); */
	d->sc.ply.sprites = malloc(sizeof(t_sprites) * 9);
	init_wp_sprites(d);
	return (0);
}

static void	ft_init_ply(t_cub *d)
{
	d->sc.ply.movespeed = MOVE_SPEED;
	d->sc.ply.ctrl.up_down = 0;
	d->sc.ply.ctrl.left_right = 0;
	d->sc.ply.ctrl.turn = 0;
	d->sc.ply.lastx = WIDTH >> 1;
	d->sc.ply.rotspeed = ROT_S;
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
	ft_init_wp(c);
	return (0);
}	

