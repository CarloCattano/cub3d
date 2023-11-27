/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/27 01:01:36 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* TODO NORME */
/* void	rayprint(t_ray *ray, int i) 
{ 
 	printf("%i ray: x%f y%f dx%f dy%f s%i \n",i, ray->hx, ray->hy, ray->rdx, 
 		ray->rdy, ray->s); 
 } 
*/
/* some more cases off offset;*/
/*
typedef struct pr
{
	t_point	plp;
	t_point	w;
	int		xoff;
	int		yoff;
}			t_pr;
*/
static void	ft_off(t_pr *p, t_ray *r, t_image *i)
{
	p->xoff = 0;
	p->yoff = 0;
	if (!r->s && r->rdy < 0 && r->rdx >= 0)
		p->yoff = fabs(i->yoff);
	else if (r->s && r->rdy < 0 && r->rdx > 0)
		p->yoff = fabs(i->yoff);
	else if (r->s && r->rdy < 0 && r->rdx < 0)
		p->yoff = fabs(i->yoff);
	else if (!r->s && r->rdy < 0 && r->rdx < 0 && r->rdx > -0.5)
		p->yoff = fabs(i->yoff);
	if (!r->s && r->rdx < 0 && r->rdy >= 0)
		p->xoff = fabs(i->xoff);
	else if (!r->s && r->rdx < 0 && r->rdy < 0)
		p->xoff = fabs(i->xoff);
	else if (r->s && r->rdx < 0 && r->rdy > 0)
		p->xoff = fabs(i->xoff);
	else if (r->s && r->rdx < 0 && r->rdy < 0)
		p->xoff = fabs(i->xoff);
}

static void	ft_ray(t_sc *s, t_image *to, t_image *o, t_ray *r)
{
	int		i;
	t_pr	p;

	i = -1;
	p.plp = cub_point((s->ply.posx * (o->xoff) + 0.5 * o->xoff + o->wxoff)
			* 0.96, (s->ply.posy * (o->yoff) + 0.5 * o->yoff + o->wyoff)
			* 0.96, RY);
	while (++i < to->w)
	{
		if (!(i % 25))
		{
			ft_off(&p, &r[i], o);
			p.w = cub_point(r[i].hx * o->xoff + p.xoff + o->wxoff, r[i].hy
					* o->yoff + p.yoff + o->wyoff, RY);
			cub_line(p.plp, p.w, to);
		}
	}
}

void	cub_draw_minimap(t_cub *c, t_ray *ray)
{
	c->mini.xoff = MWIDTH / (double)(c->sc.map.width);
	c->mini.yoff = MHEIGHT / (double)(c->sc.map.height);
	ft_map(&c->scr, &c->mini, &c->sc);
	ft_ray(&c->sc, &c->scr, &c->mini, ray);
	ft_ply(&c->scr, &c->mini, &c->sc.ply);
}
