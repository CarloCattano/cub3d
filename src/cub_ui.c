/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:46:38 by carlo             #+#    #+#             */
/*   Updated: 2023/11/23 23:03:38 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	border(t_cub *c)
{
	int	x;
	int	y;
	int	panel_origin;

	panel_origin = (WIDTH - 16) - (WIDTH >> 3);
	x = panel_origin;
	y = 0;
	while (y < HEIGHT >> 4)
	{
		x = panel_origin;
		while (x < WIDTH)
		{
			mlx_pixel_put(c->mlx, c->win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	panel(t_cub *c)
{
	int	x;
	int	y;
	int	panel_origin;

	panel_origin = (WIDTH - 16) - (WIDTH >> 3);
	x = panel_origin;
	y = 0;
	while (y + 4 < (HEIGHT >> 4) - 4)
	{
		x = panel_origin;
		while (x + 4 < WIDTH - 4)
		{
			mlx_pixel_put(c->mlx, c->win, x + 4, y + 4, 0x00000000);
			x++;
		}
		y++;
	}
}

void	show_fps(t_cub *c, char *str)
{
	int	left_corner;

	left_corner = WIDTH - (WIDTH >> 3);
	border(c);
	panel(c);
	mlx_string_put(c->mlx, c->win, left_corner - 6, 18, 0xFFFFFFFF, str);
}
