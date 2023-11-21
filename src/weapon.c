/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:09:32 by carlo             #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wp(t_cub *d)
{
	d->sc.ply.wp.path = "./res/gun3.xpm";
	d->sc.ply.wp.img.img = mlx_xpm_file_to_image(d->mlx, d->sc.ply.wp.path,
			&d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h);
	d->sc.ply.wp.img.pix = mlx_get_data_addr(d->sc.ply.wp.img.img,
			&d->sc.ply.wp.img.bpp, &d->sc.ply.wp.img.ll,
			&d->sc.ply.wp.img.endian);
}

u_int32_t	color_pixel(u_int32_t *pixel)
{
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;
	u_int8_t	alpha;

	if (pixel == NULL)
		return (0);
	red = (pixel[0] >> 24) & 0xFF;
	green = (pixel[0] >> 16) & 0xFF;
	blue = (pixel[0] >> 8) & 0xFF;
	alpha = (pixel[0]) & 0xFF;
	return (((u_int32_t)red << 24) | ((u_int32_t)green << 16)
		| ((u_int32_t)blue << 8) | (u_int32_t)alpha);
}

void	put_wp(t_cub *d, int x, int y, int color)
{
	char	*dst;

	dst = d->scr.pix + ((y + 380) * d->scr.ll + (x + 200) *(d->scr.bpp >> 3));
	*(unsigned int *)dst = color;
}

void	draw_wp(t_cub *d)
{
	int				x;
	int				y;
	int				color;
	int				index;

	x = 0;
	while (x < d->sc.ply.wp.img.w)
	{
		y = 0;
		while (y < d->sc.ply.wp.img.h)
		{
			index = (y * d->sc.ply.wp.img.ll + x * (d->sc.ply.wp.img.bpp >> 3));
			color = color_pixel((u_int32_t *)&(d->sc.ply.wp.img.pix[index]));
			if (color != (int)0xFF000000) 
				put_wp(d, x, y, color);
			y++;
		}
		x++;
	}
}
