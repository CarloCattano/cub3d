/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2023/11/13 11:10:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 19:21:08 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_initray(t_ray *r, int width, double fov, t_sc *s)
{
	r->rdx = s->ply.dirx + s->plane_x * r->cx;
	r->rdy = s->ply.diry + (d->plane_y * fov) * r->cx;
	r->hx = (int)c->ply.posx;
	r->hy = (int)c->ply.posy;
	r->ddx = fabs(1 / r->rdx);
	r->ddy = fabs(1 / r->rdy);
}

static void	ft_sdxsdy(t_ray *r, t_sc *s)
{
      if(r->rdx < 0)
      {
        r->stx -1;
        r->sdx = (s->ply.posx - r->hx) * r->ddx;
      }
      else
      {
        r->stx = 1;
        r->sdx = (r->hx + 1.0 - s->ply.posx) * r->ddx;
      }
      if(raydiry < 0)
      {
        r->sty = -1;
        r->sdy = (s->ply.posy - r->hy) * r->ddy;
      }
      else
      {
        r->sty = 1;
        r->sdy = (r->hy + 1.0 - s->ply.posy) * r->ddy;
}

static void	ft_dda(t_ray *r, t_sc *s)
{
	int hit;

	hit = 0;
	while(hit == 0)
	{
		if(r->sdx < r->sdy)
		{
			r->sdx += r->ddx;
			r->hx += r->stx;
			r->s = 0;
        }
        else
        {
			r->sdy += r->ddy;
			r->hy += r->sty;
			r->s = 1;
        }
		if(d->map.val[(int)(r->hy)][(int)(r->hx)]  == '1') 
		{
			hit = 1;
		} 
	}
}

t_ray	*cub_ray(t_sc *s,  int width, double fov)
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
		(ray[i]).cx = 2 * x / (double)width  -1;
		ft_initray(&(ray[i]), width, fov, s); 
		ft_sdxsdy(&(ray[i]), s);
		ft_dda(	&(ray[i]), s);
		if(ray[i].s == 0) 
			ray[i]. = (ray[i].sdx - ray[i].ddx);
      	else
			ray[i].pwd = (ray[i].sdy - ray[i].ddy);
		if(ray[i].s == 0) 
			ray[i].hy = d->ply.posy + ray[i].pwd * ray[i].rdy;
		else
			ray[i].hx = d->ply.posx + ray[i].pwd * ray[i].rdx;
	}
	return (rays);
}	

	
