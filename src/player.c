/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/22 17:42:11 by carlo            ###   ########.fr       */
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

static void	update_position(t_cub *d, double direction)
{
	double	movespeed;
	double	newposx;
	double	newposy;
	int		cellX;
	int		cellY;

	movespeed = d->sc.ply.movespeed;
	newposx = d->sc.ply.posx + direction * d->sc.ply.dirX * movespeed;
	newposy = d->sc.ply.posy + direction * d->sc.ply.diry * movespeed;
	cellX = (int)newposx;
	cellY = (int)newposy;
	if (d->sc.map.val[cellY][cellX] == '0')
	{
		if (d->sc.map.val[cellY][(int)d->sc.ply.posx] == '0' && fabs(newposx
				- d->sc.ply.posx) > EPSILON)
			d->sc.ply.posx = newposx;
		if (d->sc.map.val[(int)d->sc.ply.posy][cellX] == '0' && fabs(newposy
				- d->sc.ply.posy) > EPSILON)
			d->sc.ply.posy = newposy;
	}
}

void	move_ply(t_cub *d, int direction)
{
	update_position(d, direction);
}

static void	update_rotation(t_cub *d, double angle)
{
	double	olddirx;
	double	oldplane_x;

	olddirx = d->sc.ply.dirX;
	oldplane_x = d->sc.plane_x;
	d->sc.ply.dirX = olddirx * cos(angle) - d->sc.ply.diry * sin(angle);
	d->sc.ply.diry = olddirx * sin(angle) + d->sc.ply.diry * cos(angle);
	d->sc.plane_x = oldplane_x * cos(angle) - d->sc.plane_y * sin(angle);
	d->sc.plane_y = oldplane_x * sin(angle) + d->sc.plane_y * cos(angle);
}

void	rotate_ply(t_cub *d, int direction)
{
	if (direction >= 1)
		update_rotation(d, ROT_S);
	else if (direction <= -1)
		update_rotation(d, -ROT_S);
	d->sc.ply.rot = (int)(atan2(d->sc.ply.diry, d->sc.ply.dirX) * 180 / M_PI);
}

void	handle_ply(t_cub *d)
{
	move_ply(d, d->sc.ply.ctrl.up_down);
	rotate_ply(d, d->sc.ply.ctrl.turn);
}
