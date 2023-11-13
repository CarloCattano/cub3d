/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/13 14:21:15 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void ft_calculate_step_and_side_distances(t_ray *ray, t_scene *d) {
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



t_ray *cub_ray(t_scene *d,  int width)
{
	
	t_ray	*rays;
	int		i;		


	rays = (t_ray *)malloc(sizeof(t_ray) * (width + 1));		
	if (!rays)
		return (NULL);
	i = -1;
	ft_bzero(rays, sizeof(t_ray) * (width + 1));	
	while (++i < width)
	{
		//unsigned int	color = 0;
		double 			cameraX = 2 * i / (double)width - 1; //x-coordinate in camera space
		//	init ray position and direction
		double 			rayDirX = d->player.dirX + d->planeX * cameraX;
		double 			rayDirY = d->player.dirY + d->planeY * cameraX;
		//	which box of the map we're in
	  	double 			mapX = d->player.posX;
	  	double 			mapY = d->player.posY;
		//	length of ray from one x or y-side to next x or y-side
	  	double			deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
	  	double			deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
	  //	double			perpWallDist;
	  	int 			hit = 0; 		//was there a wall hit?
	  	int 			side; 			//was a NS or a EW wall hit?
		
		// DIRECTION
		//double			rayAngle = atan2(rayDirY, rayDirX); // Calculate the ray angle
		t_ray 			ray;
		
		ray.rayDirX = rayDirX;
		ray.rayDirY = rayDirY;
		ray.deltaDistX = deltaDistX;
		ray.deltaDistY = deltaDistY;
		
		ft_calculate_step_and_side_distances(&ray, d);
		//	perform DDA
//		printf("RAY %i, DIRX: %f  DIRY: %f, DISTX: %f, DISTY: %f mapX %f mapY %f \n",i, ray.rayDirX, ray.rayDirY , ray.deltaDistX, ray.deltaDistY, mapX, mapY);

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
			
			if (d->map.val[(int)mapY][(int)mapX] == '1')
			{
				printf("hit Y: %f | X; %f \n", mapY, mapX);
				hit = 1;
			}
	  	}
		ray.hitX = mapX;
		ray.hitY = mapY;
	rays[i] = ray;
	}
	return (rays);
}
/*	
  while(!done())
  {
    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = int(posX);
      int mapY = int(posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.
      double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
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
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h) drawEnd = h - 1;

      //choose wall color
      ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;    break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      }

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);*/
