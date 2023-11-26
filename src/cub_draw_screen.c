/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:43:53 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_initfp(t_ray *r, t_cub *c, t_fp *fp)
{
	get_wall_orientation(r, c, fp);
	if (r->s)
		fp->wx = r->hx;
	else
		fp->wx = r->hy;
	fp->ds = -((r->lh) >> 1) + (c->scr.h >> 1);
	if (fp->ds < 0)
		fp->ds = 0;
	fp->de = (r->lh >> 1) + (c->scr.h >> 1);
	if (fp->de >= c->scr.h)
		fp->de = c->scr.h - 1;
	fp->texx = (fp->wx * fp->tex->w);
	if (r->s == 0 && r->rdx > 0)
		fp->texx = fp->tex->w - fp->texx - 1;
	if (r->s == 1 && r->rdy < 0)
		fp->texx = fp->tex->w - fp->texx - 1;
	fp->step = (1.0 * fp->tex->h) / r->lh;
	fp->texy = (fp->ds - c->scr.h * 0.5 + r->lh * 0.5) * fp->step;
}

void	cub_draw_screen(t_cub *c, t_ray *r)
{
	int		x;
	int		y;
	t_fp	fp;

	x = -1;
	while (++x < c->scr.w)
	{
		r[x].lh = (c->scr.h / r[x].pwd);
		ft_initfp(&r[x], c, &fp);
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < fp.ds)
				cub_mpp(&(c->scr), x, y, c->sc.c_ceiling);
			else if (y >= fp.ds && y <= fp.de)
				cub_mpp(&(c->scr), x, y, cub_darken(cub_piinte(&fp), r[x].pwd));
			else if (y > fp.de)
			{
				fp.scalar = ((double)HEIGHT - y) / 16.0;
				cub_mpp(&(c->scr), x, y, cub_darken(c->sc.c_floor, fp.scalar));
			}
		}
	}
	add_frame(c);
}
