/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:36:21 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/09 00:03:47 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_variables(t_data *d)
{
	d->img.mlx = mlx_init();
	d->img.win = mlx_new_window(d->img.mlx, WIDTH, HEIGHT, "Fractol");


	if (!(d->img.mlx))
		ft_putendl_fd("failed to init mlx", 1);
	if (!(d->img.win))
		ft_putendl_fd("Error creating window", 1);

	init_img(d);
	/* init_player(d); */

	if (!d->img.image)
		ft_putendl_fd("Error creating image", 1);
	d->menu = 0;
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

