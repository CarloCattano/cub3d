/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:31:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 19:14:40 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_setwin(t_win *win)
{
	win->pp = (win->xmax + 1) * (win->ymax + 1);
	win->rscale = 1;
	win->zdiv = 1;
	win->axcoff.x = (win->xmax + 1) / 2;
	win->axcoff.y = (win->ymax + 1) / 2;
	win->move.x = 0;
	win->move.y = 0;
	win->move.cx = win->width / 2;
	win->move.cy = win->hight / 2;
}

void	fdf_setflags(t_win *win)
{
	win->flags.center = CENTER;
	win->flags.all = ALL;
	win->flags.move = MOVE;
	win->flags.colour = COLOUR;
	win->flags.orto = ORTO;
	win->flags.points = POINTS;
	win->flags.cangle = CANGLE;
	win->flags.scale = SCALE;
}

void	fdf_perangle(t_win *win)
{
	if (win->flags.orto)
		fdf_setangle(win, ISX, ISY, ISZ);
}

void	fdf_inscale(t_scale *scale)
{
	scale->xmax = 0;
	scale->xmin = HIGHTMAX;
	scale->ymax = 0;
	scale->ymin = WIDTHMAX;
}

void	fdf_init_window(t_win *win)
{
	win->wh = HIGHTMAX;
	win->ww = WIDTHMAX;
	win->hight = HIGHTMAX;
	win->width = WIDTHMAX;
	win->zmax = 0;
	win->zmin = 0;
	win->xmax = 0;
	win->ymax = 0;
	win->zoom = ZOOM;
	fdf_setflags(win);
	fdf_setangle(win, 0, 0, 0);
	fdf_perangle(win);
	fdf_inscale(&win->scale);
	win->colour = fdf_storecolour(LINE_COLOUR);
	win->icol = -1;
}
