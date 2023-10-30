/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:11:22 by carlo             #+#    #+#             */
/*   Updated: 2023/10/30 15:30:05 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>

void	init_player(t_data *d)
{
	d->player.dirX = 1;
	d->player.dirY = 0;
	d->player.posX = 4;
	d->player.posY = 4;
	d->player.moveSpeed = MOVE_SPEED;
	d->player.ctrl.up_down = 0;
	d->player.ctrl.left_right = 0;
	d->player.ctrl.turn = 0;
}

static void move_player(t_data *d, int direction)
{
    double moveSpeed = d->player.moveSpeed;
    double dirX = d->player.dirX;
    double dirY = d->player.dirY;
    double posX = d->player.posX;
    double posY = d->player.posY;

    if (direction == 1)  // Move forward
    {
        if (d->worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
            d->player.posX += dirX * moveSpeed * 0.5;
        if (d->worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
            d->player.posY += dirY * moveSpeed * 0.5;
    }
    else if (direction == -1)  // Move backward
    {
        if (d->worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
            d->player.posX -= dirX * moveSpeed * 0.5;
        if (d->worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
            d->player.posY -= dirY * moveSpeed * 0.5;
    }
}

static void rotate_player(t_data *d, int direction)
{
    double rotSpeed = ROT_S;
    double dirX = d->player.dirX;
    double dirY = d->player.dirY;
    double planeX = d->planeX;
    double planeY = d->planeY;

    if (direction == 1)  // Rotate left
    {
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
    else if (direction == -1)  // Rotate right
    {
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
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
