/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:24:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 15:15:54 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_spoint	fdf_calc(t_spoint point, t_win *win)
{	
	fdf_zoom(&point, win);
	fdf_rotation(&point, &win->angle);
	return (point);
}

static t_ppoint	*fdf_map(t_spoint *store, t_fdf *fdf)
{
	t_ppoint	*map;
	int			i;				

	i = -1;
	map = (t_ppoint *)malloc(sizeof(t_ppoint) * fdf->win.pp);
	if (!map)
		fdf_end(fdf, 1, ERR_FMP, 1);
	while (++i < fdf->win.pp)
		map[i] = fdf_render(fdf_calc(store[i], &fdf->win), &fdf->win);
	return (map);
}	

static void	fdf_scale(float *scale, t_win *w, t_scale *s)
{
	float	xmin;
	float	xmax;

	xmin = s->xmin * w->hight / w->width;
	xmax = s->xmax * w->hight / w->width;
	if ((xmax > s->ymax) && (w->width - xmax < xmin)
		&& (w->width - xmax < s->ymin))
		*scale = ((w->width - 20) / 2) / fabs(s->xmax - w->width / 2);
	if ((s->ymax > xmax) && (w->hight - s->ymax < xmin)
		&& (w->hight - s->ymax < s->ymin))
		*scale = ((w->hight - 20) / 2) / fabs(s->ymax - w->hight / 2);
	if ((xmin < s->ymin) && (w->width - xmax > xmin)
		&& (w->width - s->ymin > xmin))
		*scale = ((w->width - 20) / 2) / fabs(s->xmin - w->width / 2);
	if ((s->ymin < xmin) && (w->width - xmax > s->ymin)
		&& (w->width - s->ymin > s->ymin))
		*scale = ((w->hight -20) / 2) / fabs(s->ymin - w->hight / 2);
}

static void	fdf_centerandscale(t_ppoint *map, t_win *win)
{
	int		i;
	float	scale;

	i = -1;
	scale = win->rscale;
	if (win->flags.center)
		fdf_scale(&scale, win, &win->scale);
	if (!scale)
		scale = win->rscale;
	while (++i < win->pp)
		fdf_center(&map[i], win, scale);
	win->rscale = scale;
}

void	fdf_draw(t_fdf *fdf)
{
	t_ppoint	*map;
	t_img		img;

	fdf_img(fdf, &img);
	if (fdf->win.flags.center)
		fdf_inscale(&fdf->win.scale);
	map = fdf_map(fdf->store, fdf);
	fdf_centerandscale(map, &fdf->win);
	if (fdf->win.flags.points)
		fdf_draw_points(map, &img, &fdf->win);
	else
		fdf_draw_lines(map, &img, &fdf->win);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, img.img, 0, 0);
	free(map);
	map = NULL;
	fdf->img = img;
}
