/* /1* ************************************************************************** *1/ */
/* /1*                                                                            *1/ */
/* /1*                                                        :::      ::::::::   *1/ */
/*   player.c                                           :+:      :+:    :+:   */
/* /1*                                                    +:+ +:+         +:+     *1/ */
/* /1*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        *1/ */
/* /1*                                                +#+#+#+#+#+   +#+           *1/ */
/* /1*   Created: 2023/10/08 19:51:56 by ccattano          #+#    #+#             *1/ */
/*   Updated: 2023/10/09 00:02:20 by carlo            ###   ########.fr       */
/* /1*                                                                            *1/ */
/* /1* ************************************************************************** *1/ */

/* #include "../include/cub3d.h" */
/* #include "../minilibx-linux/mlx.h" */
/* #include <math.h> */


/* static void	draw_square(int x, int y, int w, int h, t_data *d); */

/* void	init_player(t_data *d) */
/* { */
/* 	d->player.posX = 300; */
/* 	d->player.posY = 300; */
/* 	d->player.moveSpeed = 5; */
/* 	d->player.ctrl.up_down = 0; */
/* 	d->player.ctrl.left_right = 0; */
/* 	d->player.ctrl.turn = 0; */
/* } */

/* void	cast_ray(t_data *d) */
/* { */
/* 	t_point	p1; */
/* 	t_point	p2; */

/* 	p1.x = d->player.posX; */
/* 	p1.y = d->player.posY; */
/* 	p2.x = d->player.posX + d->player.dirX * 40; */
/* 	p2.y = d->player.posY + d->player.dirY * 40; */

/* 	draw_line(d, p1, p2, 0xFFFFFF00); */
/* } */

/* void	movePlayer(t_data *d) */
/* { */
/* 	float	move_step; */
/* 	float	n_player_x; */
/* 	float	n_player_y; */
/* 	float	n_dir_x; */
/* 	float	n_dir_y; */
/* 	float	rot_angle; */
/* 	rot_angle = d->player.ctrl.turn * ROTATION_ANGLE; */
/* 	n_dir_x = d->player.dir.x * cos(rot_angle) - d->player.dir.y * sin(rot_angle); */
/* 	n_dir_y = d->player.dir.x * sin(rot_angle) + d->player.dir.y * cos(rot_angle); */
/* 	d->player.dir.x = n_dir_x; */
/* 	d->player.dir.y = n_dir_y; */

/* 	move_step = d->player.ctrl.up_down * d->player.speed; */
/* 	n_player_x = d->player.pos.x + d->player.dir.x * move_step; */
/* 	n_player_y = d->player.pos.y + d->player.dir.y * move_step; */
/* 	d->player.pos.x = n_player_x; */
/* 	d->player.pos.y = n_player_y; */

/* 	move_step = d->player.ctrl.left_right * d->player.speed; */
/* 	n_player_x = d->player.pos.x + d->player.dir.y * move_step; */
/* 	n_player_y = d->player.pos.y - d->player.dir.x * move_step; */
/* 	d->player.pos.x = n_player_x; */
/* 	d->player.pos.y = n_player_y; */
/* } */

/* void	draw_player(t_data *d) */
/* { */
/* 	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d); */
/* 	movePlayer(d); */
/* 	cast_ray(d); */
/* } */

/* static void	draw_square(int x, int y, int w, int h, t_data *d) */
/* { */
/* 	int	j; */
/* 	int	i; */

/* 	i = 0; */
/* 	while (i++ < w) */
/* 	{ */
/* 		j = 0; */
/* 		while (j++ < h) */
/* 			my_mlx_pixel_put(d, x + i, y + j, 0xFF00FFFF); */
/* 		i++; */
/* 	} */
/* } */
