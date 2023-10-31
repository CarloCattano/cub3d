/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:09:20 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 14:57:45 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fdf_draw_lines(t_ppoint *map, t_img *img, t_win *win)
{
	int	i;
	int	y;

	y = win->xmax + 1;
	i = -1;
	while (++i < win->pp)
	{
		if (i + y < win->pp)
			line(map[i], map[i + y], img, win);
		if (i + 1 < win->pp && ((i + 1) % y))
			line(map[i], map[i + 1], img, win);
		else if (i < y -1)
			line(map[i], map[i + 1], img, win);
	}
}

static void	init_line(t_ppoint *a, t_ppoint *b, t_line *l, t_win *w)
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
	l->w = (int)w->width;
	l->h = (int)w->hight;
}

static void	plotline(t_line l, t_img *data)
{
	while (1)
	{
		if (l.ax > 0 && l.ax < l.w && l.ay > 0 && l.ay < l.h)
		{
			my_mlx_pixel_put(data, l.ax, l.ay, l.colour.trgb);
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

void	line(t_ppoint a, t_ppoint b, t_img *data, t_win *win)
{
	t_line	line;

	init_line(&a, &b, &line, win);
	plotline(line, data);
}
