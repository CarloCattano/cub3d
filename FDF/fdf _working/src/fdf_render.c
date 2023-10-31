/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:59:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:32:31 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_colgrad	fdf_loadcolour(t_spoint point, t_win *win)
{
	t_colgrad	colour;

	if (!point.colour.trgb)
	{
		colour.trgb = win->colour.trgb;
		colour.t = win->colour.t;
		colour.r = win->colour.r;
		colour.g = win->colour.g;
		colour.b = win->colour.b;
	}
	else
	{
		colour.trgb = point.colour.trgb;
		colour.t = point.colour.t;
		colour.r = point.colour.r;
		colour.g = point.colour.g;
		colour.b = point.colour.b;
	}
	colour.rof = 0;
	colour.gof = 0;
	colour.bof = 0;
	return (colour);
}

static void	fdf_setscale(t_scale *scale, t_ppoint *nwpoint)
{
	if (nwpoint->x > scale->xmax)
		scale->xmax = nwpoint->x;
	if (nwpoint->x < scale->xmin)
		scale->xmin = nwpoint->x;
	if (nwpoint->y > scale->ymax)
		scale->ymax = nwpoint->y;
	if (nwpoint->y < scale->ymin)
		scale->ymin = nwpoint->y;
}

static t_ppoint	fdf_orto(t_spoint point, t_win *win)
{
	t_ppoint	nwpoint;

	nwpoint.x = point.x;
	nwpoint.y = point.y;
	nwpoint.z = point.z;
	nwpoint.colour = fdf_loadcolour(point, win);
	nwpoint.x += win->move.cx;
	nwpoint.y += win->move.cy;
	fdf_setscale(&win->scale, &nwpoint);
	nwpoint.x -= win->move.cx;
	nwpoint.y -= win->move.cy;
	return (nwpoint);
}

static t_ppoint	fdf_perspective(t_spoint point, t_win *win)
{
	t_ppoint	nwpoint;

	nwpoint.x = ((1 * point.x) / 1 * point.z);
	nwpoint.y = (1 * point.y) / 1 * point.z;
	nwpoint.z = point.z;
	nwpoint.colour = fdf_loadcolour(point, win);
	nwpoint.x += win->move.cx;
	nwpoint.y += win->move.cy;
	fdf_setscale(&win->scale, &nwpoint);
	nwpoint.x -= win->move.cx;
	nwpoint.y -= win->move.cy;
	return (nwpoint);
}

t_ppoint	fdf_render(t_spoint point, t_win *win)
{
	t_ppoint	nwpoint;

	if (win->flags.orto)
	{
		nwpoint = fdf_orto(point, win);
	}
	else
	{
		nwpoint = fdf_perspective(point, win);
	}
	return (nwpoint);
}
