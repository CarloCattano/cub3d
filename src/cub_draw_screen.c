/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 00:55:31 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* refactor TX */
/*
static void	ft_initfp(t_ray *r, t_fp *tp, t_cub *c )
{
	if (r->s)
		tp->wx = r->hx;
	else
		tp->wx = r->hy;
	tp->ds = -((r->lh) >> 1) + (c->scr.h >> 1);
	if (tp->ds < 0) 
		tp->ds = 0;
	tp->de = (r->lh >> 1) + (c->scr.h >> 1);
	if (tp->de >= c->scr.h)
		tp->de = c->scr.h - 1;
	get_wall_orientation(r, c, tp);
	tp->texx =(tp->wx * TX);
	if (r->s == 0 && r->rdx > 0) 
		tp->texx = TX - tp->texx - 1;
	if (r->s == 1 && r->rdy < 0)
		tp->texx = TX - tp->texx - 1;
	tp->fp.step = (1.0 * TY) / r->lh;
	tp->texy = (tp->ds - c->scr.h * 0.5 + r->lh * 0.5) * tp->fp.step;
}

void	cub_draw_screen(t_cub *c, t_ray *r)
{
	int		x;
	int		y;
	t_fp	tp;

	x = -1;
	while (++x < c->scr.w)
	{
		ft_initfp(&r[x], &tp, c);
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < tp.ds)
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y >= tp.ds && y <= tp.de)
				cub_mpp(&(c->scr), x, y, cub_piinte(&tp));
			else if (y > tp.de) 
			{
				tp.scalar = ((double)HEIGHT - y) / 16.0;
				cub_mpp(&(c->scr), x, y, cub_darken(c->sc.c_floor, tp.scalar));
			}
		}
	}
	mlx_put_image_to_window(c->mlx, c->win, c->scr.img, 0, 0);
	add_frame(c);
}
*/

void cub_draw_screen(t_cub *c, t_ray *ray)
{
	int 	x;
	int		y;
	t_fp fp;

	x = -1;
	while (++x < c->scr.w)
	{	
		get_wall_orientation(&ray[x], c, &fp);
		if (ray[x].s)
		   	fp.wx = ray[x].hx;
		else
			fp.wx = ray[x].hy;
		ray[x].lh = (c->scr.h / ray[x].pwd);
		fp.ds = -((ray[x].lh) >> 1) + (c->scr.h >> 1);
	  	if(fp.ds < 0) 
			  fp.ds = 0;
	  	fp.de = (ray[x].lh >> 1) + (c->scr.h >> 1);
	  	if(fp.de >= c->scr.h) 
			  fp.de = c->scr.h - 1;
	
	  	fp.texx = (fp.wx * fp.tex->w);
	  	if(ray[x].s == 0 && ray[x].rdx > 0) 
			fp.texx = fp.tex->w - fp.texx - 1;
	  	if(ray[x].s == 1 && ray[x].rdy < 0)
			fp.texx = fp.tex->w - fp.texx - 1;
	  	fp.step = (1.0 * fp.tex->h) / ray[x].lh;
	  	fp.texy = (fp.ds - c->scr.h * 0.5 + ray[x].lh * 0.5) * fp.step;
		
		
	

		y = -1;
		while (++y < HEIGHT)
		{
			if (y < fp.ds)
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y >= fp.ds && y <= fp.de)
				cub_mpp(&(c->scr), x, y,  cub_darken(cub_piinte(&fp), ray[x].pwd));
			else if (y > fp.de) 
      { 
        fp.scalar = ((double)HEIGHT - y ) / 16.0;
        cub_mpp(&(c->scr), x, y, cub_darken(c->sc.c_floor, fp.scalar));
      }
		}
	}
  mlx_put_image_to_window(c->mlx, c->win, c->scr.img, 0, 0);
	add_frame(c);
}
