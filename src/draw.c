/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/17 11:10:22 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <mlx.h>
#include <time.h>

int worldMap[MAPWIDTH][MAPHEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,5,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void verLine(int x, int drawStart, int drawEnd, int color, t_data *d)
{
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		if (y < drawStart)
			my_mlx_pixel_put(d, x, y, 0);
		else if (y > drawStart && y < drawEnd)
			my_mlx_pixel_put(d, x, y, color);
		else if (y > drawEnd)
			my_mlx_pixel_put(d, x, y, 0);
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
		double rayDirX = d->player.dirX + d->planeX * cameraX;
		double rayDirY = d->player.dirY + d->planeY * cameraX;
  		//which box of the map we're in
      	int mapX = (int)d->player.posX;
      	int mapY = (int)d->player.posY;

      	//length of ray from current position to next x or y-side
      	double sideDistX;
      	double sideDistY;

      	 //length of ray from one x or y-side to next x or y-side
      	double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
      	double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);
      	double perpWallDist;

      	//what direction to step in x or y-direction (either +1 or -1)
      	int stepX;
      	int stepY;

      	int hit = 0; //was there a wall hit?
      	int side; //was a NS or a EW wall hit?
		
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
		
		//	perform DDA
      	while (hit == 0)
      	{
      	  //jump to next map square, either in x-direction, or in y-direction
      	  if (sideDistX < sideDistY)
      	  {
      	    sideDistX += deltaDistX;
      	    mapX += stepX;
      	    side = 0;
      	  }
      	  else
      	  {
      	    sideDistY += deltaDistY;
      	    mapY += stepY;
      	    side = 1;
      	  }
	  	  //Check if ray has hit a wall
      	  if (worldMap[mapX][mapY] > 0)
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
      	if(drawStart < 0)
			drawStart = 0;
      	int drawEnd = lineHeight / 2 + HEIGHT / 2;
      	if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
   	  	
		//choose wall color
      	int	color;
      	switch(worldMap[mapX][mapY])
      	{
      	  case 1:  color = 0xFFFF0000; break; //red
      	  case 2:  color = 0xFF00FF00; break; //green
      	  case 3:  color = 0xFF0000FF; break; //blue
      	  case 4:  color = 0xFFFFFFFF; break; //white
      	  default: color = 0xFF223322; break; //yellow
      	}

      	//give x and y sides different brightness
      	if (side == 1) {color = color/ 2;}

      	//draw the pixels of the stripe as a vertical line
      	verLine(x, drawStart, drawEnd, color, d);
    }
	
	//move forward if no wall in front of you
    if (d->player.ctrl.up_down == 1)
    {
      if(worldMap[(int)(d->player.posX + d->player.dirX * d->player.moveSpeed)][(int)d->player.posY] == 0) d->player.posX += d->player.dirX * d->player.moveSpeed;
      if(worldMap[(int)d->player.posX][(int)(d->player.posY + d->player.dirY * d->player.moveSpeed)] == 0) d->player.posY += d->player.dirY * d->player.moveSpeed;
    }
    //move backwards if no wall behind you
    if (d->player.ctrl.up_down == -1)
    {
      if(worldMap[(int)(d->player.posX - d->player.dirX * d->player.moveSpeed)][(int)d->player.posY] == 0) d->player.posX -= d->player.dirX * d->player.moveSpeed;
      if(worldMap[(int)d->player.posX][(int)(d->player.posY - d->player.dirY * d->player.moveSpeed)] == 0) d->player.posY -= d->player.dirY * d->player.moveSpeed;
    }
    //rotate to the right
    if (d->player.ctrl.turn == -1)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = d->player.dirX;
      d->player.dirX = d->player.dirX * cos(-ROT_SPEED) - d->player.dirY * sin(-ROT_SPEED);
      d->player.dirY = oldDirX * sin(-ROT_SPEED) + d->player.dirY * cos(-ROT_SPEED);
      double oldPlaneX = d->planeX;
      d->planeX = d->planeX * cos(-ROT_SPEED) - d->planeY * sin(-ROT_SPEED);
      d->planeY = oldPlaneX * sin(-ROT_SPEED) + d->planeY * cos(-ROT_SPEED);
    }
    //rotate to the left
    if (d->player.ctrl.turn == 1)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = d->player.dirX;
      d->player.dirX = d->player.dirX * cos(ROT_SPEED) - d->player.dirY * sin(ROT_SPEED);
      d->player.dirY = oldDirX * sin(ROT_SPEED) + d->player.dirY * cos(ROT_SPEED);
      double oldPlaneX = d->planeX;
      d->planeX = d->planeX * cos(ROT_SPEED) - d->planeY * sin(ROT_SPEED);
      d->planeY = oldPlaneX * sin(ROT_SPEED) + d->planeY * cos(ROT_SPEED);
    }
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
	draw_player(d);
}

