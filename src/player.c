/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/11/17 15:08:28 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void	init_player(t_scene *d)
{
	//d->player.dirX = 1;
	//d->player.dirY = 0;
	d->player.moveSpeed = MOVE_SPEED;
	d->player.ctrl.up_down = 0;
	d->player.ctrl.left_right = 0;
	d->player.ctrl.turn = 0;
	d->player.lastX = WIDTH >> 1;
	d->player.rotSpeed = ROT_S;
}

void move_player(t_scene *d, int direction)
{
    double moveSpeed = d->player.moveSpeed;
    double dirX = d->player.dirX;
    double dirY = d->player.dirY;
    double posX = d->player.posX;
    double posY = d->player.posY;

    if (direction == 1)  		// Move forward
    {
        if (d->map.val[(int)(posX + dirX * moveSpeed)][(int)posY] == '0')
            d->player.posX += dirX * moveSpeed;
        if (d->map.val[(int)posX][(int)(posY + dirY * moveSpeed)] == '0')
            d->player.posY += dirY * moveSpeed;
    }
    else if (direction == -1)  	// Move backward
    {
        if (d->map.val[(int)(posX - dirX * moveSpeed)][(int)posY] == '0')
            d->player.posX -= dirX * moveSpeed;
        if (d->map.val[(int)posX][(int)(posY - dirY * moveSpeed)] == '0')
            d->player.posY -= dirY * moveSpeed;
    }
}

void rotate_player(t_scene *d, int direction)
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

void handle_player(t_scene *d)
{
	move_player(d, d->player.ctrl.up_down);
	rotate_player(d, d->player.ctrl.turn);	
}
