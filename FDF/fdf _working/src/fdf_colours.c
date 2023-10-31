/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:49:40 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 15:24:57 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_set_col(t_colgrad *col, int t)
{
	int	trgb;

	if (col->first)
	{
		col->first = 0;
		return (create_trgb(t, col->r, col->g, col->b));
	}
	trgb = create_trgb(t, col->r + col->rof,
			col->g + col->gof, col->b + col->bof);
	return (trgb);
}

int	set_div(int dx, int dy)
{
	if (abs(dx) < abs(dy))
		return (dy);
	else
		return (dx);
}

int	set_of(int r1, int r2, int div)
{
	if (r1 > r2)
		div *= -1;
	return ((int)(((r1 - r2) / div)));
}

t_colgrad	fdf_in_col(t_ppoint *a, t_ppoint *b, int dx, int dy)
{
	t_colgrad	col;
	int			div;

	if (!(a->z + b->z))
	{	
		col.r = get_r(a->colour.trgb);
		col.rof = 0;
		col.g = get_g(a->colour.trgb);
		col.gof = 0;
		col.b = get_g(a->colour.trgb);
		col.bof = 0;
	}
	else
	{	
		div = set_div(dx, dy);
		col.r = a->colour.r;
		col.rof = set_of(col.r, get_r(b->colour.trgb), div);
		col.g = a->colour.g;
		col.gof = set_of(col.g, get_g(b->colour.trgb), div);
		col.b = a->colour.b;
		col.bof = set_of(col.b, get_b(b->colour.trgb), div);
	}
	return (col);
}
