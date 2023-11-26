/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 17:42:15 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void	rayprint(t_ray *ray)
 {
 printf ("ray: x%f y%f dx%f dy%f s%i \n", ray->hx, ray->hy, ray->rdx, ray->rdy,ray->s); 	
 }

/* some more cases off offset;*/ 

typedef struct pr
{
	t_point plp;
	t_point w;
	int xoff;
	int yoff;
}t_pr;


static void	ft_off(t_pr *p, t_ray *r, t_image *i)
{ 
	p->xoff = 0;
	p->yoff = 0;
	if (!r->s && r->rdy < 0 && r->rdx >= 0)	
		p->yoff = fabs(i->yoff);
	//else if (!r->s && r->rdy < 0 && r->rdx < 0 && r->rdx > -0.5)
	//		p->yoff = fabs(i->yoff);
	else if (r->s && r->rdy < 0 &&  r->rdx > 0)
			p->yoff = fabs(i->yoff);
	else if  (r->s && r->rdy < 0   && r->rdx < 0)
			p->yoff = fabs(i->yoff);

	if (!r->s && r->rdx < 0 && r->rdy >= 0)	
			p->xoff = fabs(i->xoff);
	else if (!r->s && r->rdx < 0 && r->rdy < 0)
			p->xoff = fabs(i->xoff);
	else if (r->s && r->rdx < 0 &&  r->rdy > 0)
			p->xoff = fabs(i->xoff);
	else if (r->s &&  r->rdx < 0 && r->rdy < 0)
			p->xoff = fabs(i->xoff);

}

static void ft_ray(t_sc *s, t_image *to, t_image *o, t_ray *r)
{
	int	i;
	t_pr	p;
	i = -1;
	p.plp = cub_point(s->ply.posx * (o->xoff)  + 0.5 * o->xoff + o->wxoff,
		 s->ply.posy * (o->yoff) + 0.5 * o->yoff + o->wyoff, RY);
	// todo clear every time
	while (++i < to->w)
	{
		rayprint(&r[i]);
		if (2)
		{
			ft_off(&p, &r[i], o);
			p.w = cub_point(r[i].hx * o->xoff + p.xoff + o->wxoff
				, r[i].hy * o->yoff + p.yoff + o->wyoff, RY);
			cub_line(p.plp, p.w, to);
		}
	}
}
	
void draw_cub(t_image *img, t_image *off, t_point *a, t_point *b)
{
	int y1;
	int x1;	

	y1 = -1;
	
	while ( ++y1 < off->yoff)
	{
		x1 = -1;
		while (++x1 < off->xoff)
		{
			if (b && (!x1 ||!y1))
			{
				cub_mpp(img ,(int)(b->x + x1), (int)(b->y + y1),  b->colour);
			}
			else if (a)
			{	
				cub_mpp(img , (int)(a->x + x1), (int)(a->y  + y1), a->colour);
			}
		}
	}				
}
/*
void draw_ply(t_image *img, t_ply *pl)
{
	t_point plp;
	t_point plv2;
	t_point plv1;
	
	plp = cub_point(pl->posx * img->xoff, pl->posy * img->yoff, PL);
	plv1 = cub_point(plp.x + (0.5 * img->xoff), plp.y + (0.5 * img->yoff), PL); 
	plv2 = cub_point((plv1.x + ( 1.2 * pl->dirx * img->xoff)),  (plv1.y  + (1.2 * pl->diry  * img->yoff)), PL);
	
	draw_cub(img, false, &plp, NULL); 
	cub_line(plv1, plv2, img);
}
*/
/*
void ft_draw_minimap(t_cub *c, t_ray *ray)
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
*/



void ft_map(t_image *to, t_image *o, t_sc *s)
{
	int	y;
	int	x;
	t_point a;
	t_point	b;
    
	y = -1;
	while (++y < s->map.height)
	{	
		x = -1;
		while (++x < s->map.width)
		{
			
			a = cub_point(x * o->xoff + o->wxoff, y * o->yoff + o->wyoff, W1);
			b = cub_point(x * o->xoff + o->wxoff, y * o->yoff + o->wyoff, W2);
			if (s->map.val[y][x] == '1')
				draw_cub(to, o, &a, &b);	
			if (s->map.val[y][x] == '0')
			{
				a.colour = F1;
				b.colour = F2;
				draw_cub(to, o, NULL, &b);	
			}		
		}	
	}
}


void ft_ply(t_image *to, t_image *o, t_ply *pl)
{
	t_point plp;
    t_point plv2;
    t_point plv1;
		
	plp = cub_point(pl->posx * o->xoff + o->wxoff, pl->posy * o->yoff + o->wyoff, PL);
    plv1 = cub_point(plp.x + (0.5 * o->xoff), plp.y + (0.5 * o->yoff), PL); 
    plv2 = cub_point((plv1.x + ( 1.2 * pl->dirx * o->xoff)),
		 (plv1.y  + (1.2 * pl->diry  * o->yoff)), PL);
    draw_cub(to, o, &plp, NULL);
	cub_line(plv1, plv2, to);
}


void	cub_draw_minimap(t_cub *c, t_ray *ray)
{
	c->mini.xoff = MWIDTH / (double)(c->sc.map.width) ;
    c->mini.yoff = MHEIGHT / (double)(c->sc.map.height);
	ft_map(&c->scr, &c->mini, &c->sc);
	ft_ray(&c->sc, &c->scr, &c->mini, ray);
	ft_ply(&c->scr, &c->mini, &c->sc.ply);
	//ft_ray();
}
