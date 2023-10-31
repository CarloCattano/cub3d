/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:21:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 16:23:56 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_hock_init(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L << 0, keypress, fdf);
	mlx_hook(fdf->mlx_win, 17, 1L << 2, fdf_close, fdf);
}

int	fdf_close( t_fdf *fdf)
{
	fdf_end(fdf, 0, TXT_CR, 0);
	return (0);
}

void	fdf_keyangle(int keycode, t_fdf *fdf)
{
	if (keycode == 'q')
		fdf->win.angle.x += 0.01745329251994;
	if (keycode == 'w')
		fdf->win.angle.x -= 0.01745329251994;
	if (keycode == 'a')
		fdf->win.angle.y += 0.01745329251994;
	if (keycode == 's')
		fdf->win.angle.y -= 0.01745329251994;
	if (keycode == 'z')
		fdf->win.angle.z += 0.01745329251994;
	if (keycode == 'x')
		fdf->win.angle.z -= 0.01745329251994;
}

void	fdf_keyflags(int keycode, t_fdf *fdf)
{
	if (keycode == 'c')
	{
		if (fdf->win.flags.center)
			fdf->win.flags.center = 0;
		else
			fdf->win.flags.center = 1;
	}
	if (keycode == '1')
	{
		if (fdf->win.flags.orto)
			fdf->win.flags.orto = 0;
		else
			fdf->win.flags.orto = 1;
	}
}

int	keypress(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		fdf_end(fdf, 0, TXT_EXP, 0);
	if (keycode == 32)
		fdf_keycolour(fdf);
	if (keycode == '1' || keycode == 'c')
		fdf_keyflags(keycode, fdf);
	if (keycode == 'q' || keycode == 'w' || keycode == 'a' || keycode == 's'
		|| keycode == 'z' || keycode == 'x')
		fdf_keyangle(keycode, fdf);
	if (keycode >= 65361 && keycode <= 65364)
		fdf_keymove(keycode, fdf);
	if (keycode == 'g' || keycode == 'h')
		fdf_keyzoom(keycode, fdf);
	if (keycode == 'b' || keycode == 'n')
		fdf_keyzdiv(keycode, fdf);
	if (keycode == 96)
		fdf_keyrest(fdf);
	fdf_draw(fdf);
	return (0);
}

/*	
	if (keycode == 'e')
		fdf->win.axoff.x += 0.5;
	if (keycode == 'r')
		fdf->win.axoff.x -= 0.5;
	if (keycode == 'd')
		fdf->win.axoff.y += 0.5;
	if (keycode == 'f')
		fdf->win.axoff.y -= 0.5;
	if (keycode == 'c')
		fdf->win.axoff.z += 0.5;
	if (keycode == 'v')
		fdf->win.axoff.z -= 0.5;
	if (keycode == '5')
	{
		if (fdf->win.flags.axce)
            fdf->win.flags.axce = 0;
        else
            fdf->win.flags.axce = 1;
	}	
	
	if (keycode == '6')
    {
        if (fdf->win.flags.axmo)
            fdf->win.flags.axmo = 0;
        else
            fdf->win.flags.axmo = 1;
    }
*/
