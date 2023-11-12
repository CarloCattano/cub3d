/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/12 17:11:38 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_cub(t_image *img, bool edge, t_point *a, t_point *b)
{
	int y1;
	int x1;	

	y1 = -1;
	while ( ++y1 < img->yoff)
	{
		x1 = -1;
		while (++x1 < img->xoff)
		{
			if (edge && (!x1 ||!y1))
				cub_mpp(img ,(int)(b->x + x1), (int)(b->y + y1),  b->colour);
			else
				cub_mpp(img , (int)(a->x + x1), (int)(a->y  + y1), a->colour);
		}
	}				
}


void draw_player(t_image *img, t_player *pl)
{
	t_point plp;
	t_point plv2;
	t_point plv1;
	
	plp = cub_point(pl->posX * img->xoff, pl->posY * img->yoff, PL);
	plv1 = cub_point(plp.x + (0.5 * img->xoff), plp.y + (0.5 * img->yoff), PL); 
	plv2 = cub_point((plv1.x + ( 1.2 * pl->dirX  * img->xoff)),  (plv1.y  + (1.2 * pl->dirY  * img->yoff)), PL);
	
	draw_cub(img, false, &plp, NULL); 
	cub_line(plv1, plv2, img);
}





void cub_draw_minimap(t_cub *c)
{
	double xoff;
	double yoff;
	int	x;
	int y;
	

	//int px;
	//int py;
	int x1;
	int y1;

	xoff = MWIDTH / (double)(c->scene.map.width) ;
	yoff = MHEIGHT / (double)(c->scene.map.height);
	c->mini.xoff = xoff;
	c->mini.yoff = yoff;
	
	printf ("%f / %f  ]\n", xoff, yoff);

	y = -1;
	while (++y < c->scene.map.height)
	{
		x = -1;
		while (++x < c->scene.map.width)
		{
			if (c->scene.map.val[y][x] == '1')
			{		
				y1 = -1;
				while ( ++y1 < yoff)
				{
					x1 = -1;
					while (++x1 < xoff)
					{	
							if (!x1 ||!y1)
								cub_mpp(&(c->mini) ,(int)(x * xoff + x1), (int)(y * yoff + y1) ,  W2);
							else
								cub_mpp(&(c->mini) , (int)(x * xoff + x1), (int)(y * yoff + y1) ,  W1);
					}
				}				
		
			}
			
			else if (c->scene.map.val[y][x] == '0')
			{
				y1 = -1;
				while ( ++y1 < yoff)
				{
					x1 = -1;
					while (++x1 < xoff)
					{	
						if (!x1 || !y1)
							cub_mpp(&(c->mini) ,(int)(x * xoff + x1), (int)(y * yoff + y1) ,  F1);
						else
							cub_mpp(&(c->mini) ,(int)(x * xoff + x1),(int)(y *yoff + y1),  F2);
					}
				}				
			}
			else
				printf("out: %c\n", c->scene.map.val[y][x]);
		}
	
	}		
	cub_mpp(&(c->mini) , MWIDTH / 2, MHEIGHT / 2,  F1);
	draw_player(&(c->mini), &(c->scene.player));
	mlx_put_image_to_window(c->mlx, c->win, c->mini.img, 5, 5);	
	

}
