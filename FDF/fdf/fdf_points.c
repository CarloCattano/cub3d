/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:49:51 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:28:54 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fdf_draw_points(t_ppoint *map, t_img *img, t_win *win)
{
	int	i;

	i = -1;
	while (++i < win ->pp)
	{
		if (map[i].x >= 0 && map[i].x <= win->width
			&& map[i].y >= 0 && map[i].y <= win->hight)
			my_mlx_pixel_put(img, (int)map[i].x,
				(int)map[i].y, map[i].colour.trgb);
	}
}

void	fdf_center(t_ppoint *nwpoint, t_win *win, int scale)
{
	nwpoint->x *= scale;
	nwpoint->y *= scale;
	nwpoint->x += win->move.cx;
	nwpoint->y += win->move.cy;
	if (win->flags.move)
	{
		nwpoint->x += win->move.x;
		nwpoint->y += win->move.y;
	}
}
