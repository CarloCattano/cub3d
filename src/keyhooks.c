/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:32 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/27 13:09:38 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_codes.h"

int	key_down_hook(int k, t_cub *d)
{
	if (k == KEY_UP || k == KEY_W)
		d->sc.ply.ctrl.up_down = 1;
	else if (k == KEY_DOWN || k == KEY_S)
		d->sc.ply.ctrl.up_down = -1;
	if (k == KEY_A)
		d->sc.ply.ctrl.left_right = -1;
	else if (k == KEY_D)
		d->sc.ply.ctrl.left_right = 1;
	if (k == KEY_LEFT)
		d->sc.ply.ctrl.turn = -1;
	else if (k == KEY_RIGHT)
		d->sc.ply.ctrl.turn = 1;
	if (k == KEY_SPACE)
		d->sc.ply.shooting = 1;
	if (k == KEY_ESCAPE)
		mlx_terminate(d);
	if (k == LEFT_SHIFT)
		d->sc.ply.movespeed = MOVE_SPEED * 2;
	return (k);
}

int	key_up_hook(int k, t_cub *d)
{
	if (k == KEY_UP || k == KEY_DOWN || k == KEY_S || k == KEY_W)
		d->sc.ply.ctrl.up_down = 0;
	if (k == KEY_A || k == KEY_D)
		d->sc.ply.ctrl.left_right = 0;
	if (k == KEY_LEFT || k == KEY_RIGHT)
		d->sc.ply.ctrl.turn = 0;
	if (k == KEY_SPACE)
	{
		d->sc.ply.shooting = 0;
		cub_open_door(d);
	}
	if (k == KEY_ESCAPE)
		mlx_terminate(d);
	if (k == KEY_M)
		d->bonus = !d->bonus;
	if (k == LEFT_SHIFT)
		d->sc.ply.movespeed = MOVE_SPEED / 2;
	return (k);
}
