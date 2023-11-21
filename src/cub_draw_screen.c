/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:21 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */

#include "cube3d.h"
#include <stdio.h>

void cub_draw_screen(t_cub *c, t_ray *ray)
{
	int x;
	int y;
	double wallX;

	x = -1;
	while (++x < c->scr.w)
	{
		if (ray[x].side)
           	wallX = ray[x].hitX;
		else
			wallX = ray[x].hitY;
		ray[x].lineHeight = (int)(c->scr.h /ray[x].perpWallDist);
		int drawStart = -(ray[x].lineHeight) / 2 + c->scr.h / 2;
      	if(drawStart < 0) 
			drawStart = 0;
      	int drawEnd = ray[x].lineHeight / 2 + c->scr.h / 2;
      	if(drawEnd >= c->scr.h) 
			drawEnd = c->scr.h - 1;
	
		//x coordinate on the texture
      	int texX = (int)(wallX * (double)TX);
      	if(ray[x].side == 0 && ray[x].raydirX > 0) 
			texX = TX - texX - 1;
      	if(ray[x].side == 1 && ray[x].raydiry < 0) 
			texX = TX - texX - 1;
      	// How much to increase the texture coordinate per scr pixel
      	double step = 1.0 * TY / ray[x].lineHeight;
      	// Starting texture coordinate
      	double texPos = (drawStart - c->scr.h / 2.0 + ray[x].lineHeight / 2.0) * step;
		
		t_fp fp;
		
		fp.tex = &(c->sc.wall[0]);
		fp.texX = texX;
		fp.step = step;
		fp.texY = texPos;	
		
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < drawStart)	// ceiling
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y > drawStart && y < drawEnd)
			{
				cub_mpp(&(c->scr), x, y,  cub_piinte(&fp)); 
			}
			else if (y > drawEnd) // floor
				cub_mpp(&(c->scr), x, y, c->sc.c_floor);
		}
	}
	 mlx_put_image_to_window(c->mlx, c->win, c->scr.img, 0, 0);
}
