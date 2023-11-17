/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/17 17:26:12 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *d)
{
	d->scene.player.dirX = 1;
	d->scene.player.dirY = 0;
	d->scene.player.posX = 4;
	d->scene.player.posY = 4;
	d->scene.player.moveSpeed = MOVE_SPEED;
	d->scene.player.ctrl.up_down = 0;
	d->scene.player.ctrl.left_right = 0;
	d->scene.player.ctrl.turn = 0;
	d->scene.player.lastX = WIDTH >> 1;
	d->scene.player.rotSpeed = ROT_S;
}

static void move_player(t_data *d, int direction)
{
    double moveSpeed = d->player.moveSpeed;
    double dirX = d->player.dirX;
    double dirY = d->player.dirY;
    double posX = d->player.posX;
    double posY = d->player.posY;
	
    if (direction == 1)  		// Move forward
    {
        if (d->worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
            d->player.posX += dirX * moveSpeed;
        if (d->worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
            d->player.posY += dirY * moveSpeed;
    }
    else if (direction == -1)  	// Move backward
    {
        if (d->worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
            d->player.posX -= dirX * moveSpeed;
        if (d->worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
            d->player.posY -= dirY * moveSpeed;
    }
}

void rotate_player(t_data *d, int direction)
{
    double dirX = d->player.dirX;
    double dirY = d->player.dirY;
    double planeX = d->planeX;
    double planeY = d->planeY;

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

    d->player.dirX = dirX;
    d->player.dirY = dirY;
    d->planeX = planeX;
    d->planeY = planeY;
}

void handle_player(t_data *d)
{
	move_player(d, d->player.ctrl.up_down);
	rotate_player(d, d->player.ctrl.turn);	
}
