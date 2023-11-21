/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/22 00:04:18 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ray[x].lineHeight = (c->scr.h / ray[x].perpWallDist);
		int drawStart = -((ray[x].lineHeight) >> 1) + (c->scr.h >> 1);
      	if(drawStart < 0) 
			drawStart = 0;
      	int drawEnd = (ray[x].lineHeight >> 1) + (c->scr.h >> 1);
      	if(drawEnd >= c->scr.h) 
			drawEnd = c->scr.h - 1;
	
      	int texX = (wallX * TX) + 1;
      	if(ray[x].side == 0 && ray[x].raydirX > 0) 
			texX = TX - texX - 1;
      	if(ray[x].side == 1 && ray[x].raydiry < 0)
			texX = TX - texX - 1;
      	// How much to increase the texture coordinate per scr pixel
      	double step = (1.0 * TY) / ray[x].lineHeight;
      	// Starting texture coordinate
      	double texPos = (drawStart - c->scr.h * 0.5 + ray[x].lineHeight * 0.5) * step;
		
		t_fp fp;
		
		//fp.tex = &(c->sc.wall[0]);
		fp.texX = texX;
		fp.step = step;
		fp.texY = texPos;
		get_wall_orientation(&ray[x], c, &fp);
		// get_wall_texture(c, &ray[x], fp);
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < drawStart)
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y > drawStart && y < drawEnd)
				cub_mpp(&(c->scr), x, y,  cub_piinte(&fp)); 
			else if (y > drawEnd) 
				cub_mpp(&(c->scr), x, y, c->sc.c_floor);
		}
	}
	 mlx_put_image_to_window(c->mlx, c->win, c->scr.img, 0, 0);
}
