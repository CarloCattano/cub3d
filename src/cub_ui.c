/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:46:38 by carlo             #+#    #+#             */
/*   Updated: 2023/11/23 22:17:47 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	panel(t_cub *c)
{
	int	x;
	int	y;

	x = WIDTH - (WIDTH >> 3);
	y = 0;
	while (y < HEIGHT >> 4)
	{
		x = WIDTH - (WIDTH >> 3);
		while (x < WIDTH)
		{
			mlx_pixel_put(c->mlx, c->win, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	show_fps(t_cub *c, char *str)
{
	int	left_corner;

	left_corner = WIDTH - (WIDTH >> 3) + 30;
	panel(c);
	mlx_string_put(c->mlx, c->win, left_corner, 10, 0xFFFFFFFF , str); //0x00FFFFFF, "FPS: HELLO WORLD! ");
}
