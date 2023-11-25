/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/25 22:54:48 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	lateral_movement(t_cub *d, int direction)
{
	double	m_speed;
	double	new_x;
	double	new_y;
	int		cellx;
	int		celly;

	m_speed = d->sc.ply.movespeed;
	new_x = d->sc.ply.posx + direction * d->sc.plane_x * m_speed;
	new_y = d->sc.ply.posy + direction * d->sc.plane_y * m_speed;
	cellx = (int)new_x;
	celly = (int)new_y;
	if (d->sc.map.val[celly][cellx] == '0')
	{
		if (d->sc.map.val[celly][(int)d->sc.ply.posx] == '0' && fabs(new_x
				- d->sc.ply.posx) > EPSILON)
			d->sc.ply.posx = new_x;
		if (d->sc.map.val[(int)d->sc.ply.posy][cellx] == '0' && fabs(new_y
				- d->sc.ply.posy) > EPSILON)
			d->sc.ply.posy = new_y;
	}
}

static void	update_position(t_cub *d, double direction)
{
	double	m_speed;
	double	new_x;
	double	new_y;
	int		cellx;
	int		celly;

	m_speed = d->sc.ply.movespeed;
	new_x = d->sc.ply.posx + direction * d->sc.ply.dirx * m_speed;
	new_y = d->sc.ply.posy + direction * d->sc.ply.diry * m_speed;
	cellx = (int)new_x;
	celly = (int)new_y;
	if (d->sc.map.val[celly][cellx] == '0')
	{
		if (d->sc.map.val[celly][(int)d->sc.ply.posx] == '0' && fabs(new_x
				- d->sc.ply.posx) > EPSILON)
			d->sc.ply.posx = new_x;
		if (d->sc.map.val[(int)d->sc.ply.posy][cellx] == '0' && fabs(new_y
				- d->sc.ply.posy) > EPSILON)
			d->sc.ply.posy = new_y;
	}
}

static void	update_rotation(t_cub *d, double angle)
{
	double	olddirx;
	double	oldplane_x;

	olddirx = d->sc.ply.dirx;
	oldplane_x = d->sc.plane_x;
	d->sc.ply.dirx = olddirx * cos(angle) - d->sc.ply.diry * sin(angle);
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
	d->sc.ply.rot = (int)(atan2(d->sc.ply.diry, d->sc.ply.dirx) * 180 / M_PI);
}

void	handle_ply(t_cub *d)
{
	update_position(d, d->sc.ply.ctrl.up_down);
	rotate_ply(d, d->sc.ply.ctrl.turn);
	lateral_movement(d, d->sc.ply.ctrl.left_right);
}
