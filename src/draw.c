/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/30 15:30:29 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <mlx.h>
#include <time.h>

static void vertical_line(int x, int drawStart, int drawEnd, unsigned int color, t_data *d)
{
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		if (y < drawStart)
			my_mlx_pixel_put(d, x, y, 0xFF0000FF);
		else if (y > drawStart && y < drawEnd)
			my_mlx_pixel_put(d, x, y, color);
		else if (y > drawEnd)
			my_mlx_pixel_put(d, x, y, 0xAA008800);
	}
}

void	clr_ctx(t_data *d)
{
	ft_bzero(d->img.data, WIDTH * HEIGHT * (d->img.bpp / 8));
}

void	draw(t_data *d)
{
	int	x;

	x = 0;
	clr_ctx(d);
	while (x++ < WIDTH)
	{
		double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
		//	init ray position and direction
		double rayDirX = d->player.dirX + d->planeX * cameraX;
		double rayDirY = d->player.dirY + d->planeY * cameraX;
		//	which box of the map we're in
	  	int mapX = (int)d->player.posX;
	  	int mapY = (int)d->player.posY;
		//	length of ray from current position to next x or y-side
	  	double sideDistX;
	  	double sideDistY;
		//	length of ray from one x or y-side to next x or y-side
	  	double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1.0 / rayDirX);
	  	double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1.0 / rayDirY);
	  	double perpWallDist;
	  	//what direction to step in x or y-direction (either +1 or -1)
	  	int stepX;
	  	int stepY;
	  	int hit = 0; 		//was there a wall hit?
	  	int side; 			//was a NS or a EW wall hit?
		//	calculate step and initial sideDist
	  	if (rayDirX < 0)
	  	{
	  	  stepX = -1;
	  	  sideDistX = (d->player.posX - mapX) * deltaDistX;
	  	}
	  	else
	  	{
	  	  stepX = 1;
	  	  sideDistX = (mapX + 1.0 - d->player.posX) * deltaDistX;
	  	}
	  	if (rayDirY < 0)
	  	{
	  	  stepY = -1;
	  	  sideDistY = (d->player.posY - mapY) * deltaDistY;
	  	}
	  	else
	  	{
	  	  stepY = 1;
	  	  sideDistY = (mapY + 1.0 - d->player.posY) * deltaDistY;
	  	}
		
		// DIRECTION
		double rayAngle = atan2(rayDirY, rayDirX); // Calculate the ray angle

        // Determine the cardinal direction
        char wallDirection;
        if (rayAngle >= -M_PI_4 && rayAngle < M_PI_4)
            wallDirection = 'E'; // East
        else if (rayAngle >= M_PI_4 && rayAngle < 3 * M_PI_4)
            wallDirection = 'S'; // South
        else if (rayAngle >= -3 * M_PI_4 && rayAngle < -M_PI_4)
            wallDirection = 'N'; // North
        else
            wallDirection = 'W'; // West

		//	perform DDA
	  	while (hit == 0)
	  	{
	        //jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
	  	  	{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
	  	  	} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
	  		}
			//Check if ray has hit a wall
			if (d->worldMap[mapX][mapY] > 0)
				hit = 1;
	  	}
		//	Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	  	if(side == 0)
		{
			perpWallDist = (sideDistX - deltaDistX);
		} else {
			perpWallDist = (sideDistY - deltaDistY);
		}
		//	Calculate height of line to draw on screen
	  	int lineHeight = (int)(HEIGHT / perpWallDist);
	  	//calculate lowest and highest pixel to fill in current stripe
	  	int drawStart = -lineHeight / 2 + HEIGHT / 2;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
	  	if(drawStart < 0)
			drawStart = 0;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		//choose wall color
	  	unsigned int	color = 0;
		if (d->worldMap[mapX][mapY] == 1)
		{
			if (wallDirection == 'N')
                color = 0xFF0000FF; // Blue for North-facing walls
            else if (wallDirection == 'S')
                color = 0xFF00FF00; // Green for South-facing walls
            else if (wallDirection == 'E')
                color = 0xFFFF0000; // Red for East-facing walls
            else if (wallDirection == 'W')
                color = 0xFF00FFFF; // Cyan for West-facing walls
			
		}
	  	//give x and y sides different brightness
	  	//if (side == 1) color = color >> 1;
	  	//draw the pixels of the stripe as a vertical line
	  	vertical_line(x, drawStart, drawEnd, color, d);
	}

	handle_player(d);
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
	draw_minimap(d);
}

