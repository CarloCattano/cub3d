/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:41 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/27 12:56:35 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	entered(t_cub *d)
{
	(void)d;
	return (0);
}

int	exited(t_cub *d)
{
	if (d->sc.ply.lastx > WIDTH - 10)
	{
		mlx_mouse_move(d->mlx, d->win, WIDTH - 10, HEIGHT >> 1);
		d->sc.ply.lastx = WIDTH - 10;
	}
	else
	{
		mlx_mouse_move(d->mlx, d->win, WIDTH - 10, HEIGHT >> 1);
		d->sc.ply.lastx = 10;
	}
	return (0);
}

int	motion_hook(int x, int y, t_cub *d)
{
	if (x > d->sc.ply.lastx)
	{
		d->sc.ply.rotspeed = (d->sc.ply.lastx - x) * 10.0;
		rotate_ply(d, 1);
	}
	else
	{
		d->sc.ply.rotspeed = (d->sc.ply.lastx - x) * 10.0;
		rotate_ply(d, -1);
	}
	(void)y;
	d->sc.ply.lastx = x;
	return (0);
}

int	mouse_buttons(int k, int x, int y, t_cub *d)
{
	if ((k == 1 || k == 2)
		&& (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == 1 || k == 2)
		{
			cub_open_door(d);
			d->sc.ply.shooting = !d->sc.ply.shooting;
		}
	}
	return (0);
}
