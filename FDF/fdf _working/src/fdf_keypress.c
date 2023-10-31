/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:01:44 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_keycolour(t_fdf *fdf)
{
	if (fdf->win.icol < 7)
		fdf->win.icol++;
	else
		fdf->win.icol = -1;
	if (fdf->win.icol == -1)
		fdf->win.colour = fdf_storecolour(LINE_COLOUR);
	if (fdf->win.icol == 0)
		fdf->win.colour = fdf_storecolour(RED);
	if (fdf->win.icol == 1)
		fdf->win.colour = fdf_storecolour(GREEN);
	if (fdf->win.icol == 2)
		fdf->win.colour = fdf_storecolour(BLUE);
	if (fdf->win.icol == 3)
		fdf->win.colour = fdf_storecolour(YELLOW);
	if (fdf->win.icol == 4)
		fdf->win.colour = fdf_storecolour(WHITE);
	if (fdf->win.icol == 5)
		fdf->win.colour = fdf_storecolour(PINK);
	if (fdf->win.icol == 6)
		fdf->win.colour = fdf_storecolour(HBLUE);
}

void	fdf_keymove(int keycode, t_fdf *fdf)
{
	if (keycode == 65363)
		fdf->win.move.x += 10;
	if (keycode == 65361)
		fdf->win.move.x -= 10;
	if (keycode == 65364)
		fdf->win.move.y += 10;
	if (keycode == 65362)
		fdf->win.move.y -= 10;
}

void	fdf_keyrest(t_fdf *fdf)
{
	fdf->win.rscale = 1;
	fdf->win.zdiv = 1;
	fdf->win.axcoff.x = (fdf->win.xmax + 1) / 2;
	fdf->win.axcoff.y = (fdf->win.ymax + 1) / 2;
	fdf->win.move.x = 0;
	fdf->win.move.y = 0;
	fdf->win.zoom = ZOOM;
	fdf_setflags(&fdf->win);
	fdf_setangle(&fdf->win, 0, 0, 0);
	fdf_perangle(&fdf->win);
	fdf->win.colour = fdf_storecolour(LINE_COLOUR);
}

void	fdf_keyzdiv(int keycode, t_fdf *fdf)
{
	if (keycode == 'b')
	{
		if (fdf->win.zdiv > 1)
			fdf->win.zdiv += 0.25;
		else
			fdf->win.zdiv += 0.01;
	}
	if (keycode == 'n')
	{
		if (fdf->win.zdiv > 1)
			fdf->win.zdiv -= 0.25;
		else
			fdf->win.zdiv -= 0.01;
	}
}

void	fdf_keyzoom(int keycode, t_fdf *fdf)
{
	fdf->win.flags.center = 0;
	if (keycode == 'g')
		fdf->win.zoom -= 0.25;
	if (keycode == 'h')
		fdf->win.zoom += 0.5;
}
