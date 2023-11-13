/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/13 21:23:24 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray *cub_ray(t_scene *d,  int width)
{
	
	t_ray	*rays;
	int		x;		


	rays = (t_ray *)malloc(sizeof(t_ray) * width);		
	if (!rays)
		return (NULL);
	x = -1;
	ft_bzero(rays, sizeof(t_ray) * width);	
	while (++x < width)
	{
		double 			cameraX = 2 * x / (double)width  -1; //x-coordinate in camera space
		//	init ray position and direction
		double 			rayDirX = d->player.dirX + d->planeX * cameraX;
		double 			rayDirY = d->player.dirY + d->planeY * cameraX;
		//	which box of the map we're in
	  	int 			mapX = (int)d->player.posX;
	  	int 			mapY = (int)d->player.posY;

 //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
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
        sideDistX = (d->player.posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - d->player.posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (d->player.posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - d->player.posY) * deltaDistY;
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
        if(d->map.val[mapY][mapX]  == '1') 
		{
			hit = 1;
		}
      }

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = d->player.posY + perpWallDist * rayDirY;
      else          wallX = d->player.posX + perpWallDist * rayDirX;
	
		t_ray ray;
		
		ray.rayDirX = rayDirX;
    	ray.rayDirY = rayDirY;
    	ray.deltaDistX = deltaDistX;
    	ray.deltaDistY = deltaDistY;
    	ray.stepX = stepX; 
    	ray.stepY = stepY;
    	ray.sideDistX = sideDistX;
    	ray.sideDistY = sideDistY;
    	ray.side = side;
		if (ray.side)
		{
    		ray.hitX = wallX;
    		ray.hitY = mapY;
		}
		else
		{
    		ray.hitX = mapX; 
    		ray.hitY = wallX;
		}
		rays[x] = ray; 
	}
	return (rays);
}	

	
