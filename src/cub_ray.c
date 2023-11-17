/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:17:31 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray *cub_ray(t_sc *d,  int width, double fov)
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
		double 			raydirX = d->ply.dirX + d->plane_x * cameraX;
		double 			raydiry = d->ply.diry + (d->plane_y * fov) * cameraX;
		//	which box of the map we're in
	  	int 			mapX = (int)d->ply.posx;
	  	int 			mapY = (int)d->ply.posy;

 //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

/*      double deltaDistX = sqrt(1 + (raydiry * raydiry) / (raydirX * raydirX));
      double deltaDistY = sqrt(1 + (raydirX * raydirX) / (raydiry * raydiry));
*/	//length of ray from one x or y-side to next x or y-side
      double deltaDistX = (raydirX == 0) ? 1e30 : fabs(1 / raydirX);
      double deltaDistY = (raydiry == 0) ? 1e30 : fabs(1 / raydiry);
      double perpWallDist;
	
/*	ray.delta.x = 1e30;
	ray.delta.y = 1e30;*/
      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(raydirX < 0)
      {
        stepX = -1;
        sideDistX = (d->ply.posx - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - d->ply.posx) * deltaDistX;
      }
      if(raydiry < 0)
      {
        stepY = -1;
        sideDistY = (d->ply.posy - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - d->ply.posy) * deltaDistY;
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
      if(side == 0) wallX = d->ply.posy + perpWallDist * raydiry;
      else          wallX = d->ply.posx + perpWallDist * raydirX;
	
		t_ray ray;
		
		ray.raydirX = raydirX;
    	ray.raydiry = raydiry;
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
		ray.perpWallDist = perpWallDist;
		rays[x] = ray; 
	}
	return (rays);
}	

	
