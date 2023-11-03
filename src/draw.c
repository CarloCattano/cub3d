/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/03 16:41:44 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <mlx.h>
#include <time.h>
// copied from stackoverflow.com/questions/34250742/how-to-draw-a-vertical-line-in-c-without-using-graphics-h
static void vertical_line(int x, int drawStart, int drawEnd, unsigned int color, t_data *d)
{
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		if (y < drawStart)	// ceiling
			my_mlx_pixel_put(d, x, y, 0xFF0000FF);
		else if (y > drawStart && y < drawEnd)
			my_mlx_pixel_put(d, x, y, color);
		else if (y > drawEnd) // floor
			my_mlx_pixel_put(d, x, y, 0xAA008800);
	}
}

void	clr_ctx(t_data *d)
{
	ft_bzero(d->img.data, WIDTH * HEIGHT * (d->img.bpp / 8));
}

void calculate_step_and_side_distances(t_ray *ray, t_data *d) {
    if (ray->rayDirX < 0) {
        ray->stepX = -1;
        ray->sideDistX = (d->player.posX - (int)d->player.posX) * ray->deltaDistX;
    }
    else {
        ray->stepX = 1;
        ray->sideDistX = ((int)d->player.posX + 1.0 - d->player.posX) * ray->deltaDistX;
    }
    
    if (ray->rayDirY < 0) {
        ray->stepY = -1;
        ray->sideDistY = (d->player.posY - (int)d->player.posY) * ray->deltaDistY;
    }
    else {
        ray->stepY = 1;
        ray->sideDistY = ((int)d->player.posY + 1.0 - d->player.posY) * ray->deltaDistY;
    }
}

char wall_orientation(double rayAngle)
{
    char Direction;

    if (rayAngle >= -M_PI_4 && rayAngle < M_PI_4)
        Direction = 'E'; // East
    else if (rayAngle >= M_PI_4 && rayAngle < 3 * M_PI_4)
        Direction = 'S'; // South
    else if (rayAngle >= -3 * M_PI_4 && rayAngle < -M_PI_4)
        Direction = 'N'; // North
    else
        Direction = 'W'; // West

    return Direction;
}

void	draw(t_data *d)
{
	int	x;

	x = 0;
	clr_ctx(d);
	while (x++ < WIDTH)
	{
		unsigned int	color = 0;
		double 			cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
		//	init ray position and direction
		double 			rayDirX = d->player.dirX + d->planeX * cameraX;
		double 			rayDirY = d->player.dirY + d->planeY * cameraX;
		//	which box of the map we're in
	  	int 			mapX = (int)d->player.posX;
	  	int 			mapY = (int)d->player.posY;
		//	length of ray from one x or y-side to next x or y-side
	  	double			deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1.0 / rayDirX);
	  	double			deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1.0 / rayDirY);
	  	double			perpWallDist;
	  	int 			hit = 0; 		//was there a wall hit?
	  	int 			side; 			//was a NS or a EW wall hit?
		
		// DIRECTION
		double			rayAngle = atan2(rayDirY, rayDirX); // Calculate the ray angle
		t_ray 			ray;
		
		ray.rayDirX = rayDirX;
		ray.rayDirY = rayDirY;
		ray.deltaDistX = deltaDistX;
		ray.deltaDistY = deltaDistY;

		calculate_step_and_side_distances(&ray, d);
		
        // Determine the wall orientation
        char wallDirection = wall_orientation(rayAngle);

		//	perform DDA
	  	while (hit == 0)
	  	{
	        //jump to next map square, either in x-direction, or in y-direction
			if (ray.sideDistX < ray.sideDistY)
	  	  	{
				ray.sideDistX += ray.deltaDistX;
				mapX += ray.stepX;
				side = 0;
	  	  	} else {
				ray.sideDistY += ray.deltaDistY;
				mapY += ray.stepY;
				side = 1;
	  		}
			//Check if ray has hit a wall
			if (d->worldMap[mapX][mapY] > 0)
				hit = 1;
	  	}
		//	Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	  	if(side == 0)
		{
			perpWallDist = (ray.sideDistX - ray.deltaDistX);
		} else {
			perpWallDist = (ray.sideDistY - ray.deltaDistY);
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

		if (d->worldMap[mapX][mapY] == 1)
		{
			// if (wallDirection == 'N')
            //     color = 0xFF0000FF; // Blue for North-facing walls
            // else if (wallDirection == 'S')
            //     color = 0xFF00FF00; // Green for South-facing walls
            // else if (wallDirection == 'E')
            //     color = 0xFFFF0000; // Red for East-facing walls
            // else if (wallDirection == 'W')
			(void)wallDirection;
                color = 0xFF00FFFF; // Cyan for West-facing walls
		}
	  	//give x and y sides different brightness
	  	if (side == 1) color = color >> 1;
	  	//draw the pixels of the stripe as a vertical line
	  	vertical_line(x, drawStart, drawEnd, color, d);
	}

	handle_player(d);
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
	draw_minimap(d);
}

