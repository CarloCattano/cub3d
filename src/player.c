/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/17 19:06:31 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void	init_player(t_cub *d)
{
	d->scene.player.moveSpeed = MOVE_SPEED;
	d->scene.player.ctrl.up_down = 0;
	d->scene.player.ctrl.left_right = 0;
	d->scene.player.ctrl.turn = 0;
	d->scene.player.lastX = WIDTH >> 1;
	d->scene.player.rotSpeed = ROT_S;
}

void move_player(t_cub *d, int direction)
{
    double moveSpeed = d->scene.player.moveSpeed;
    double dirX = d->scene.player.dirX;
    double dirY = d->scene.player.dirY;
    double posX = d->scene.player.posX;
    double posY = d->scene.player.posY;

    double newPosX = posX + direction * dirX * moveSpeed;
    double newPosY = posY + direction * dirY * moveSpeed;

    int cellX = (int)newPosX;
    int cellY = (int)newPosY;

    if (d->scene.map.val[cellY][cellX] == '0')
    {
        if (d->scene.map.val[cellY][(int)posX] == '0' && fabs(newPosX - posX) > EPSILON)
            d->scene.player.posX = newPosX;
        if (d->scene.map.val[(int)posY][cellX] == '0' && fabs(newPosY - posY) > EPSILON)
            d->scene.player.posY = newPosY;
    }
}

void rotate_player(t_cub *d, int direction)
{
    double dirX = d->scene.player.dirX;
    double dirY = d->scene.player.dirY;
    double planeX = d->scene.planeX;
    double planeY = d->scene.planeY;

    if (direction >= 1)  		// Rotate left
    {
        double oldDirX = dirX;
        dirX = dirX * cos(ROT_S) - dirY * sin(ROT_S);
        dirY = oldDirX * sin(ROT_S) + dirY * cos(ROT_S);
        double oldPlaneX = planeX;
        planeX = planeX * cos(ROT_S) - planeY * sin(ROT_S);
        planeY = oldPlaneX * sin(ROT_S) + planeY * cos(ROT_S);
    }
    else if (direction <= -1)  // Rotate right
    {
        double oldDirX = dirX;
        double oldPlaneX = planeX;
        
		dirX = dirX * cos(-ROT_S) - dirY * sin(-ROT_S);
        dirY = oldDirX * sin(-ROT_S) + dirY * cos(-ROT_S);
        planeX = planeX * cos(-ROT_S) - planeY * sin(-ROT_S);
        planeY = oldPlaneX * sin(-ROT_S) + planeY * cos(-ROT_S);
    }

    d->scene.player.dirX = dirX;
    d->scene.player.dirY = dirY;
    d->scene.planeX = planeX;
    d->scene.planeY = planeY;
}

void handle_player(t_cub *d)
{
	move_player(d, d->scene.player.ctrl.up_down);
	rotate_player(d, d->scene.player.ctrl.turn);	
}
