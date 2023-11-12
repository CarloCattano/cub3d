/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:01:30 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/12 15:58:05 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube3d.h"


static void	init_line(t_point *a, t_point *b, t_line *l, t_image *w)
{
	l->ax = (int)a->x;
	l->ay = (int)a->y;
	l->bx = (int)b->x;
	l->by = (int)b->y;
	l->dx = abs(l->bx - l->ax);
	l->dy = -abs(l->by - l-> ay);
	l->err = l->dx + l->dy;
	l->e2 = 2 * l->err;
	if (l->ax < l->bx)
		l->sx = 1;
	else
		l->sx = -1;
	if (l->ay < l->by)
		l->sy = 1;
	else
		l->sy = -1;
	l->colour = a->colour;
	l->w = w->w;
	l->h = w->h;
}

static void	plotline(t_line l, t_image *data)
{
	while (1)
	{
		if (l.ax > 0 && l.ax < l.w && l.ay > 0 && l.ay < l.h)
		{
			cub_mpp(data, l.ax, l.ay, l.colour);
		}
		l.e2 = 2 * l.err;
		if (l.e2 >= l.dy)
		{
			if (l.ax == l.bx)
				break ;
			l.err += l.dy;
			l.ax += l.sx;
		}
		if (l.e2 <= l.dx)
		{
			if (l.ay == l.by)
				break ;
			l.err += l.dx;
			l.ay += l.sy;
		}
	}
}

void	cub_line(t_point a, t_point b, t_image *data)
{
	t_line	line;

	init_line(&a, &b, &line, data);
	plotline(line, data);
}
