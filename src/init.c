/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:36:21 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/09 01:33:05 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_data *d)
{
	int	bpp;
	int	sizeline;
	int	endian;

	d->mmap.image = mlx_new_image(d->img.mlx, 180, 180);
	d->mmap.data = mlx_get_data_addr(d->mmap.image, &bpp, &sizeline, &endian);
	d->mmap.bpp = bpp;
	d->mmap.sizeline = sizeline;
	d->mmap.endian = endian;
	ft_memset(d->mmap.data, 0xFFFFFFFF, 180 * 180 * (bpp / 8));
}

int	init_variables(t_data *d)
{
	d->img.mlx = mlx_init();
	d->img.win = mlx_new_window(d->img.mlx, WIDTH, HEIGHT, "Fractol");
	if (!(d->img.mlx))
		ft_putendl_fd("failed to init mlx", 1);
	if (!(d->img.win))
		ft_putendl_fd("Error creating window", 1);
	init_img(d);
	init_minimap(d);
	init_player(d);
	if (!d->img.image)
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
	int	sizeline;
	int	endian;

	d->img.image = mlx_new_image(d->img.mlx, WIDTH, HEIGHT);
	d->img.data = mlx_get_data_addr(d->img.image, &bpp, &sizeline, &endian);
	d->img.bpp = bpp;
	d->img.sizeline = sizeline;
	d->img.endian = endian;
}


