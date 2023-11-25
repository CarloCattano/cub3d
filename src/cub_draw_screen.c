/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 22:13:29 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* refactor TX */
static void	ft_initfp(t_ray *r, t_fp *tp, t_cub *c)
{
	if (ray->s)
		tp->wx = r->.hx;
	else
		tp->wx = r->.hy;
	tp->ds = -((r->lh) >> 1) + (c->scr.h >> 1);
	if (tp->ds < 0) 
		tp->ds = 0;
	tp->de = (r->lh >> 1) + (c->scr.h >> 1);
	if (tp->de >= c->scr.h)
		draw = c->scr.h - 1;
	get_wall_orientation(&ray[x], c, &fp);
	tp->texx = (tp->wx * tp->tex.w) + 1;
	if (r->s == 0 && r->rdx > 0) 
		tp->texx = tp->tex.w - tp->texx - 1;
	if (r->s == 1 && r->rdy < 0)
		tp->texx = tp->tex.w - tp->texx - 1;
	tp->step = (1.0 * tp->tex.h) / r->lh;
	tp->texy = (tp->ds - c->scr.h * 0.5 + r->lh * 0.5) * tp->step;
}

void	cub_draw_screen(t_cub *c, t_ray *r)
{
	int		x;
	int		y;
	t_fp	tp;

	x = -1;
	while (++x < c->scr.w)
	{
		ft_initfp(&(r[x]), &tp, c);
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < tp.ds)
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y >= tp.ds && y <= tp.de)
				cub_mpp(&(c->scr), x, y, cub_darken(cub_piinte(&fp), r[x].pwd));
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
