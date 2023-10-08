/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/08 20:26:52 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <mlx.h>
#include <time.h>

void	draw_line(t_data *d, t_point p1, t_point p2, int color)
{
	int			i;
	t_point		delta;
	t_point		sign;
	t_point		abs_delta;
	t_point		current;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;

	abs_delta = delta;
	sign.x = delta.x > 0 ? 1 : -1;
	sign.y = delta.y > 0 ? 1 : -1;
	current = p1;
	i = 0;
	while (i <= ft_max(abs_delta.x, abs_delta.y))
	{
		my_mlx_pixel_put(d, current.x, current.y, color);
		current.x += sign.x;
		current.y += sign.y;
		i++;
	}
}

void	clr_ctx(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(d, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
}

static void	grid_display(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (i % BLOCK == 0 || j % BLOCK == 0)
				my_mlx_pixel_put(d, i, j, 0xAAFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw(t_data *d)
{
	clr_ctx(d);
	grid_display(d);
	draw_player(d);
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
}



