/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:41 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/06 10:57:59 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
	mouse pos 
*/

int	entered(t_data *d)
{
	(void)d;
	return 0;
}

int	exited(t_data *d)
{
	if (d->player.lastX > WIDTH - 10)
	{	
		mlx_mouse_move(d->mlx,d->win ,WIDTH - 10, HEIGHT >> 1);
		d->player.lastX = WIDTH - 10;
	}
	else
	{
		mlx_mouse_move(d->mlx,d->win ,10, HEIGHT >> 1);
		d->player.lastX = 10;
	}
	return 0;
}

int	motion_hook(int x, int y, t_data *d)
{
	if (x > d->player.lastX)
	{
		d->player.rotSpeed = (d->player.lastX - x) * 10.0;
		rotate_player(d, 1);
	}
	else
	{
		d->player.rotSpeed = (d->player.lastX - x) * 10.0;
		rotate_player(d, -1);
	}
	(void)y;
	d->player.lastX = x;
	return (0);
}


int	mouse_buttons(int k, int x, int y, t_data *d)
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
