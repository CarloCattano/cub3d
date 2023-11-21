/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ply(t_cub *d)
{
	d->sc.ply.movespeed = MOVE_SPEED;
	d->sc.ply.ctrl.up_down = 0;
	d->sc.ply.ctrl.left_right = 0;
	d->sc.ply.ctrl.turn = 0;
	d->sc.ply.lastX = WIDTH >> 1;
	d->sc.ply.rotSpeed = ROT_S;
}

void	move_ply(t_cub *d, int direction)
{
	double movespeed = d->sc.ply.movespeed;
	double dirX = d->sc.ply.dirX;
	double diry = d->sc.ply.diry;
	double posx = d->sc.ply.posx;
	double posy = d->sc.ply.posy;
	double newposx = posx + direction * dirX * movespeed;
	double newposy = posy + direction * diry * movespeed;
	int cellX = (int)newposx;
	int cellY = (int)newposy;

	if (d->sc.map.val[cellY][cellX] == '0')
	{
		if (d->sc.map.val[cellY][(int)posx] == '0' &&
			fabs(newposx - posx) > EPSILON)
			d->sc.ply.posx = newposx;
		if (d->sc.map.val[(int)posy][cellX] == '0' &&
			fabs(newposy - posy) > EPSILON)
			d->sc.ply.posy = newposy;
	}
}

void	rotate_ply(t_cub *d, int direction)
{
	double	dirX = d->sc.ply.dirX;
	double	diry = d->sc.ply.diry;
	double	plane_x = d->sc.plane_x;
	double	plane_y = d->sc.plane_y;

	if (direction >= 1)
	{
		double	olddirX = dirX;
		dirX = dirX * cos(ROT_S) - diry * sin(ROT_S);
		diry = olddirX * sin(ROT_S) + diry * cos(ROT_S);
		double	oldplane_x = plane_x;
		plane_x = plane_x * cos(ROT_S) - plane_y * sin(ROT_S);
		plane_y = oldplane_x * sin(ROT_S) + plane_y * cos(ROT_S);
	}
	else if (direction <= -1)
	{
		double	olddirX = dirX;
		double	oldplane_x = plane_x;
		dirX = dirX * cos(-ROT_S) - diry * sin(-ROT_S);
		diry = olddirX * sin(-ROT_S) + diry * cos(-ROT_S);
		plane_x = plane_x * cos(-ROT_S) - plane_y * sin(-ROT_S);
		plane_y = oldplane_x * sin(-ROT_S) + plane_y * cos(-ROT_S);
	}

	d->sc.ply.rot = (int)(atan2(diry, dirX) * 180 / M_PI);
	d->sc.ply.dirX = dirX;
	d->sc.ply.diry = diry;
	d->sc.plane_x = plane_x;
	d->sc.plane_y = plane_y;
}

void	handle_ply(t_cub *d)
{
	move_ply(d, d->sc.ply.ctrl.up_down);
	rotate_ply(d, d->sc.ply.ctrl.turn);
}
