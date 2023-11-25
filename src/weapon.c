/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:09:32 by carlo             #+#    #+#             */
/*   Updated: 2023/11/25 17:44:26 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wp(t_cub *d)
{
	d->sc.ply.wp.path = "./res/gun/gun.xpm";
	d->sc.ply.wp.img.img = mlx_xpm_file_to_image(d->mlx, d->sc.ply.wp.path,
			&d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h);
	d->sc.ply.wp.img.pix = mlx_get_data_addr(d->sc.ply.wp.img.img,
			&d->sc.ply.wp.img.bpp, &d->sc.ply.wp.img.ll,
			&d->sc.ply.wp.img.endian);
	d->sc.ply.sprites = malloc(sizeof(t_sprites) * 9);
	init_wp_sprites(d);
}

void	put_wp(t_cub *d, int x, int y, int color)
{
	char	*dst;

	x = d->sc.ply.wp_s + x;
	y = d->sc.ply.wp_s + y;
	dst = d->scr.pix + ((y + 380) * d->scr.ll + (x + 200) * (d->scr.bpp >> 3));
	*(unsigned int *)dst = color;
}

static void	when_shooting(t_cub *d)
{
	static int	j = 0;

	if (d->sc.ply.shooting)
	{
		if (d->frame % 8 == 0)
			j++;
		d->sc.ply.wp.img = *d->sc.ply.sprites[j].img;
	}
	else
		d->sc.ply.wp.img = *d->sc.ply.sprites[0].img;
	if (d->sc.ply.shooting && j >= 7)
	{
		d->sc.ply.shooting = 0;
		j = 7;
	}
	else if (j >= 7 && !d->sc.ply.shooting)
		j = 0;
}

void	draw_wp(t_cub *d)
{
	int			x;
	int			y;
	int			color;
	int			index;

	when_shooting(d);
	x = 0;
	while (x++ < d->sc.ply.wp.img.w)
	{
		y = 0;
		while (y++ < d->sc.ply.wp.img.h)
		{
			index = (y * d->sc.ply.wp.img.ll + x * (d->sc.ply.wp.img.bpp >> 3));
			color = color_pixel((u_int32_t *)&(d->sc.ply.wp.img.pix[index]));
			if (color != (int)0xFF000000)
				put_wp(d, x, y, color);
		}
	}
}
