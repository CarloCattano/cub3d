/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_dmpl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:54:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/27 01:04:46 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cub(t_image *img, t_image *off, t_point *a, t_point *b)
{
	int	y1;
	int	x1;

	y1 = -1;
	while (++y1 < off->yoff)
	{
		x1 = -1;
		while (++x1 < off->xoff)
		{
			if (b && (!x1 || !y1))
			{
				cub_mpp(img, (int)(b->x + x1), (int)(b->y + y1), b->colour);
			}
			else if (a)
			{
				cub_mpp(img, (int)(a->x + x1), (int)(a->y + y1), a->colour);
			}
		}
	}
}

void	ft_map(t_image *to, t_image *o, t_sc *s)
{
	int		y;
	int		x;
	t_point	a;
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

void	ft_ply(t_image *to, t_image *o, t_ply *pl)
{
	t_point	plp;
	t_point	plv2;
	t_point	plv1;

	plp = cub_point((pl->posx * o->xoff + o->wxoff) 
			* 0.96, (pl->posy * o->yoff + o->wyoff) * 0.96, PL);
	plv1 = cub_point(plp.x + (0.5 * o->xoff), plp.y 
			+ (0.5 * o->yoff), PL);
	plv2 = cub_point((plv1.x + (1.2 * pl->dirx * o->xoff)), 
			(plv1.y + (1.2 * pl->diry * o->yoff)), PL);
	draw_cub(to, o, &plp, NULL);
	cub_line(plv1, plv2, to);
}
