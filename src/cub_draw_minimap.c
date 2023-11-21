/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	rayprint(t_ray *ray)
// {
// printf ("ray: x%f y%f dx%f dy%f s%i \n", ray->hitX, ray->hitY, ray->raydirX, ray->raydiry,ray->side); 	
// }

/* some more cases off offset;*/ 

void draw_rays(t_image *img, t_sc *sc, int width, t_ray *ray)
{
	t_point plp;
	t_point w;
	//(void)img;
	int xoff;
	int yoff;
	int i;
	i = -1;
	plp = cub_point(sc->ply.posx *(img->xoff)  + 0.5 * img->xoff, sc->ply.posy * (img->yoff) + 0.5 * img->yoff, RY);
	// todo clear every time
	while (++i < width)
	{
		//rayprint(&(ray[i]));
		xoff = 0;
		yoff = 0;
		if (ray[i].raydiry  < 0 && ray[i].raydirX >= 0 && !ray[i].side)	
			yoff = fabs(img->yoff);
		else if (ray[i].raydiry  < 0 && ray[i].raydirX < 0 && !ray[i].side)
			yoff = fabs(img->yoff);
		else if (ray[i].raydiry   < 0 &&  ray[i].raydirX > 0 && ray[i].side)
			yoff = fabs(img->yoff);
		else if  (ray[i].raydiry   < 0 && ray[i].raydirX < 0 && ray[i].side)
			yoff = fabs(img->yoff);
		if (ray[i].raydirX  < 0 && ray[i].raydiry >= 0 && !ray[i].side)	
			xoff = fabs(img->xoff);
		else if (ray[i].raydirX  < 0 && ray[i].raydiry < 0 && !ray[i].side)
			xoff = fabs(img->xoff);
		else if (ray[i].raydirX   < 0 &&  ray[i].raydiry > 0 && ray[i].side)
			xoff = fabs(img->xoff);
		else if  (ray[i].raydirX   < 0 && ray[i].raydiry < 0 && ray[i].side)
			xoff = fabs(img->xoff);
		w = cub_point(ray[i].hitX * img->xoff + xoff, ray[i].hitY * img->yoff +yoff, RY);
		cub_line(plp, w, img);
	}
}
	
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

void draw_ply(t_image *img, t_ply *pl)
{
	t_point plp;
	t_point plv2;
	t_point plv1;
	
	plp = cub_point(pl->posx * img->xoff, pl->posy * img->yoff, PL);
	plv1 = cub_point(plp.x + (0.5 * img->xoff), plp.y + (0.5 * img->yoff), PL); 
	plv2 = cub_point((plv1.x + ( 1.2 * pl->dirX  * img->xoff)),  (plv1.y  + (1.2 * pl->diry  * img->yoff)), PL);
	
	draw_cub(img, false, &plp, NULL); 
	cub_line(plv1, plv2, img);
}

void cub_draw_minimap(t_cub *c, t_ray *ray)
{
	double xoff;
	double yoff;
	int	x;
	int y;
	

	//int px;
	//int py;
	int x1;
	int y1;

	xoff = MWIDTH / (double)(c->sc.map.width) ;
	yoff = MHEIGHT / (double)(c->sc.map.height);
	c->mini.xoff = xoff;
	c->mini.yoff = yoff;
	

	y = -1;
	while (++y < c->sc.map.height)
	{
		x = -1;
		while (++x < c->sc.map.width)
		{
			if (c->sc.map.val[y][x] == '1')
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
			
			else if (c->sc.map.val[y][x] == '0')
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
		}
	
	}		
	draw_rays(&(c->mini), &(c->sc), c->scr.w, ray);
	draw_ply(&(c->mini), &(c->sc.ply));
	mlx_put_image_to_window(c->mlx, c->win, c->mini.img, 5, 5);	
	

}
