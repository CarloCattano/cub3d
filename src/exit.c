/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:16 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/30 14:24:13 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mlx_terminate(t_data *d)
{
	mlx_destroy_image(d->img.mlx, d->img.image);
	mlx_destroy_window(d->img.mlx, d->img.win);
	mlx_destroy_display(d->img.mlx);
	free(d->img.mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	exit (0);
	return (0);
}