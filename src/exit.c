/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:16 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/22 16:58:11 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef __linux__

int	mlx_terminate(t_cub *d)
{
	mlx_destroy_image(d->mlx, d->scr.img);
	mlx_destroy_image(d->mlx, d->sc.ply.wp.img.img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	exit (0);
}

#else

int	mlx_terminate(t_cub *d)
{
	mlx_destroy_image(d->mlx, d->scr.img);
	mlx_destroy_image(d->mlx, d->sc.ply.wp.img.img);
	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	return (0);
}

#endif
