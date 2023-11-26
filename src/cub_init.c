/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:22:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 22:35:42 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_txt(int i)
{
	char	*paths[9];

	paths[0] = "./res/gun/gun.xpm";
	paths[1] = "./res/gun/gun1.xpm";
	paths[2] = "./res/gun/gun2.xpm";
	paths[3] = "./res/gun/gun3.xpm";
	paths[4] = "./res/gun/gun4.xpm";
	paths[5] = "./res/gun/gun5.xpm";
	paths[6] = "./res/gun/gun6.xpm";
	paths[7] = "./res/gun/gun7.xpm";
	paths[8] = "./res/gun/gun8.xpm";
	return (paths[i]);
}

static int	init_wp_sprites(t_cub *c)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < 9)
	{
		fd = open(ft_txt(i), O_RDONLY);
		if (fd < 0)
			return (cub_error(E_SOTF, 2, NULL, NULL));
		close(fd);
		c->sc.ply.sprites[i].img = malloc(sizeof(t_image));
		if (!(c->sc.ply.sprites[i].img))
			return (cub_error(E_MAL, 1, NULL, NULL));
		if (cub_loadfile(c->sc.ply.sprites[i].img, c->mlx, ft_txt(i)))
			return (cub_error(E_WL, 1, NULL, NULL));
	}
	return (0);
}

static int	ft_init_wp(t_cub *d)
{
	d->sc.ply.sprites = malloc(sizeof(t_sprites) * 9);
	if (!d->sc.ply.sprites)
		return (cub_error(E_MAL, 1, NULL, NULL));
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
	c->scr.pix = mlx_get_data_addr(c->scr.img, &c->scr.bpp, &c->scr.ll,
			&c->scr.endian);
	c->scr.h = HEIGHT;
	c->scr.w = WIDTH;
	c->mini.h = MHEIGHT;
	c->mini.w = MWIDTH;
	c->mini.xoff = MWIDTH / (double)(c->sc.map.width);
	c->mini.yoff = MHEIGHT / (double)(c->sc.map.height);
	c->mini.wxoff = 5;
	c->mini.wyoff = 5;
	ft_init_ply(c);
	if (ft_init_wp(c))
		return (1);
	init_hook(c);
	return (0);
}
