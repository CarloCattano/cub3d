/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 16:29:06 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void cub_draw(t_cub *c)
{
	t_ray *ray;

	int x;
	int y;

	ray = cub_ray(&(c->sc), width, FOV);
	int lineHeight = (int)(h / perpWallDist);
	int drawStart = -lineHeight / 2 + h / 2;
      	if(drawStart < 0) drawStart = 0;
      		int drawEnd = lineHeight / 2 + h / 2;
      	if(drawEnd >= h) drawEnd = h - 1;
int texX = int(wallX * double(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;		
      //x coordinate on the texture
      int texX = int(wallX * double(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];	

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
				cub_mpp(&(c->screen), x, y, c->scene.c_floor);
		}
	}
	 mlx_put_image_to_window(c->mlx, c->win, c->screen.img, 0, 0);
}
