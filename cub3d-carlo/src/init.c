/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:36:21 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/06 13:29:55 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_data *d)
{
	d->mmap.img = mlx_new_image(d->mlx, 180, 180);
	d->mmap.pix = mlx_get_data_addr(d->mmap.img, &(d->mmap.bpp), &d->mmap.line_lenght, &d->mmap.endian);
	ft_memset(d->mmap.pix, 0xFFFFFFFF, 180 * 180 * ( d->mmap.bpp >> 3));
}

int	init_variables(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!(d->mlx))
		ft_putendl_fd("failed to init mlx", 1);
	if (!(d->win))
		ft_putendl_fd("Error creating window", 1);
	init_img(d);
	init_minimap(d);
	init_player(d);
	init_weapon(d);
	if (!d->img.img)
		ft_putendl_fd("Error creating image", 1);
	d->planeX = 0;
	d->planeY = 0.86;
	return (1);
}

/*
	Initialize image
*/
void	init_img(t_data *d)
{
	int	bpp;
	int	line_lenght;
	int	endian;

	d->img.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img.pix = mlx_get_data_addr(d->img.img, &bpp, &line_lenght, &endian);
	d->img.bpp = bpp;
	d->img.line_lenght = line_lenght;
	d->img.endian = endian;
}


