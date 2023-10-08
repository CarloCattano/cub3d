/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:51:56 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/08 20:27:10 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>

#define ROTATION_ANGLE 0.04f

static void	draw_square(int x, int y, int w, int h, t_data *d);

void	init_player(t_data *d)
{
	d->player.pos.x = 300;
	d->player.pos.y = 300;

	d->player.dir.x = 1;
	d->player.dir.y = 1;

	d->player.speed = 1;
	d->player.ctrl.up_down = 0;
	d->player.ctrl.left_right = 0;
	d->player.ctrl.turn = 0;
}

void	cast_ray(t_data *d)
{
	t_point	p1;
	t_point	p2;

	p1.x = d->player.pos.x;
	p1.y = d->player.pos.y;
	p2.x = d->player.pos.x + d->player.dir.x * 40;
	p2.y = d->player.pos.y + d->player.dir.y * 40;

	draw_line(d, p1, p2, 0xFFFFFF00);
}

void	movePlayer(t_data *d)
{
	float	move_step;
	float	n_player_x;
	float	n_player_y;
	float	n_dir_x;
	float	n_dir_y;
	float	rot_angle;
	rot_angle = d->player.ctrl.turn * ROTATION_ANGLE;
	n_dir_x = d->player.dir.x * cos(rot_angle) - d->player.dir.y * sin(rot_angle);
	n_dir_y = d->player.dir.x * sin(rot_angle) + d->player.dir.y * cos(rot_angle);
	d->player.dir.x = n_dir_x;
	d->player.dir.y = n_dir_y;

	move_step = d->player.ctrl.up_down * d->player.speed;
	n_player_x = d->player.pos.x + d->player.dir.x * move_step;
	n_player_y = d->player.pos.y + d->player.dir.y * move_step;
	d->player.pos.x = n_player_x;
	d->player.pos.y = n_player_y;

	move_step = d->player.ctrl.left_right * d->player.speed;
	n_player_x = d->player.pos.x + d->player.dir.y * move_step;
	n_player_y = d->player.pos.y - d->player.dir.x * move_step;
	d->player.pos.x = n_player_x;
	d->player.pos.y = n_player_y;
}


void	draw_player(t_data *d)
{
	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);
	movePlayer(d);
	cast_ray(d);
}

static void	draw_square(int x, int y, int w, int h, t_data *d)
{
	int	j;
	int	i;

	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			my_mlx_pixel_put(d, x + i, y + j, 0xFF00FFFF);
			j++;
		}
		i++;
	}
}
