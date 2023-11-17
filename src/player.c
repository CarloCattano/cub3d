/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/17 19:27:56 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_player(t_cub *d)
{
	d->scene.player.movespeed = MOVE_SPEED;
	d->scene.player.ctrl.up_down = 0;
	d->scene.player.ctrl.left_right = 0;
	d->scene.player.ctrl.turn = 0;
	d->scene.player.lastX = WIDTH >> 1;
	d->scene.player.rotSpeed = ROT_S;
}

void	move_player(t_cub *d, int direction)
{
	double movespeed = d->scene.player.movespeed;
	double dirX = d->scene.player.dirX;
	double diry = d->scene.player.diry;
	double posx = d->scene.player.posx;
	double posy = d->scene.player.posy;
	double newposx = posx + direction * dirX * movespeed;
	double newposy = posy + direction * diry * movespeed;
	int cellX = (int)newposx;
	int cellY = (int)newposy;

	if (d->scene.map.val[cellY][cellX] == '0')
	{
		if (d->scene.map.val[cellY][(int)posx] == '0' &&
			fabs(newposx - posx) > EPSILON)
			d->scene.player.posx = newposx;
		if (d->scene.map.val[(int)posy][cellX] == '0' &&
			fabs(newposy - posy) > EPSILON)
			d->scene.player.posy = newposy;
	}
}

void	rotate_player(t_cub *d, int direction)
{
	double	dirX = d->scene.player.dirX;
	double	diry = d->scene.player.diry;
	double	plane_x = d->scene.plane_x;
	double	plane_y = d->scene.plane_y;

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
	d->scene.player.dirX = dirX;
	d->scene.player.diry = diry;
	d->scene.plane_x = plane_x;
	d->scene.plane_y = plane_y;
}

void	handle_player(t_cub *d)
{
	move_player(d, d->scene.player.ctrl.up_down);
	rotate_player(d, d->scene.player.ctrl.turn);
}
