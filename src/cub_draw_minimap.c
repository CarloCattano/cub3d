/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 19:05:13 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


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
	
	printf ("%f / %f i ]\n", xoff, yoff);

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
							if (!x1 ||/* x1 == (xoff - 1) ||*/ !y1 /*|| y1 == (yoff -1)*/)
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
						if (!x1 /*|| x1 == (xoff - 1)*/ || !y1/* || y1 == (yoff -1)*/)
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
//1	cub_mpp(&(c->mini) , MWIDTH / 2, MHEIGHT / 2,  F1);
	mlx_put_image_to_window(c->mlx, c->win, c->mini.img, 5, 5);	
	

}
