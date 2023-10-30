/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/10/30 14:39:02 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>

static void	draw_square(int x, int y, int w, int h, t_data *d);

void	init_player(t_data *d)
{
	d->player.dirX = 1;
	d->player.dirY = 0;
	d->player.posX = 4;
	d->player.posY = 4;
	d->player.moveSpeed = MOVE_SPEED;
	d->player.ctrl.up_down = 0;
	d->player.ctrl.left_right = 0;
	d->player.ctrl.turn = 0;
}

void	draw_minimap(t_data *d)
{
	double scaled = 180.0 / MAPWIDTH;
	double posX = d->player.posX * scaled;
	double posY = d->player.posY * scaled;

	ft_bzero(d->mmap.data, 180 * 180 * (d->mmap.bpp / 8));
	draw_square(posX, posY, 10, 10, d);
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->mmap.image, 0, 0);
}

void	put_minimap(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mmap.data + (y * d->mmap.sizeline + x * (d->mmap.bpp >> 3));
	*(unsigned int *)dst = color;
}

static void	draw_square(int x, int y, int w, int h, t_data *d)
{
	int	j;
	int	i;

	i = 0;
	while (i++ < w)
	{
		j = 0;
		while (j++ < h)
			put_minimap(d, x + i, y + j, 0xFFFF0000);
		i++;
	}
}
