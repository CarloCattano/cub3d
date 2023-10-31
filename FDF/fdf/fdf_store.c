/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:50:56 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/01/31 13:16:07 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_rpoint	*fdf_pop(t_rpoint **data)
{
	t_rpoint	*pars;

	pars = *data;
	*data = pars->next;
	return (pars);
}

t_colour	fdf_storecolour(int trgb)
{
	t_colour	colour;

	if (!trgb)
		colour.trgb = trgb;
	else
	{
		colour.trgb = trgb;
		colour.t = get_t(trgb);
		colour.r = get_r(trgb);
		colour.g = get_g(trgb);
		colour.b = get_b(trgb);
	}
	return (colour);
}

/* decide good scale and proportion */
t_spoint	fdf_spoint(t_rpoint *pars, t_win *win)
{
	t_spoint	store;

	store.x = (pars->x - win->axcoff.x) * win->rscale;
	store.y = (pars->y - win->axcoff.y) * win->rscale;
	store.z = pars->z * win->rscale;
	store.colour = fdf_storecolour(pars->trgb);
	free(pars);
	pars = NULL;
	return (store);
}

t_spoint	*fdf_store(t_rpoint	**data, t_win *win)
{
	t_spoint	*store;
	int			i;

	store = NULL;
	if (!data)
		return (NULL);
	fdf_setwin(win);
	i = 1;
	store = (t_spoint *)malloc(sizeof(t_spoint) * win->pp);
	if (!store)
		return (NULL);
	while (i <= win->pp)
	{
		store[win->pp - i] = fdf_spoint(fdf_pop(data), win);
		i++;
	}
	return (store);
}
