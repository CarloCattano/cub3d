/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:41 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/17 22:17:31 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
	mouse pos 
*/

int	entered(t_cub *d)
{
	(void)d;
	return (0);
}

int	exited(t_cub *d)
{
	if (d->sc.ply.lastX > WIDTH - 10)
	{
		mlx_mouse_move(d->mlx,d->win ,WIDTH - 10, HEIGHT >> 1);
		d->sc.ply.lastX = WIDTH - 10;
	}
	else
	{
		mlx_mouse_move(d->mlx,d->win ,10, HEIGHT >> 1);
		d->sc.ply.lastX = 10;
	}
	return 0;
}

int	motion_hook(int x, int y, t_cub *d)
{
	if (x > d->sc.ply.lastX)
	{
		d->sc.ply.rotSpeed = (d->sc.ply.lastX - x) * 10.0;
		rotate_ply(d, 1);
	}
	else
	{
		d->sc.ply.rotSpeed = (d->sc.ply.lastX - x) * 10.0;
		rotate_ply(d, -1);
	}
	(void)y;
	d->sc.ply.lastX = x;
	return (0);
}


int	mouse_buttons(int k, int x, int y, t_sc *d)
{
	(void)d;
	if ((k == 1 || k == 2)
		&& (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == MOUSE_LEFT || k == MOUSE_RIGHT)
		{
		}
	}
	return (0);
}
