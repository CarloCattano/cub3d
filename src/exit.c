/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:16 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/21 17:58:03 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_terminate(t_cub *d)
{
	mlx_destroy_image(d->mlx, d->scr.img);
	mlx_destroy_image(d->mlx, d->sc.ply.wp.img.img);
	mlx_destroy_window(d->mlx, d->win);
	#ifdef __linux__
	mlx_destroy_display(d->mlx);
	#endif
	free(d->mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	exit (0);
}


