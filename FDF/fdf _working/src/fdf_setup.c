/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:08:27 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/01 16:30:04 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_setup(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->win.ww,
			fdf->win.wh, WTEXT);
	fdf_img(fdf, &fdf->img);
	fdf_hock_init(fdf);
}

void	fdf_img(t_fdf *fdf, t_img *img)
{
	img->img = mlx_new_image(fdf->mlx, fdf->win.ww, (int)fdf->win.wh);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
