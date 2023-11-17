/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:32 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/17 19:28:56 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "key_codes.h"

int	key_down_hook(int k, t_cub *d)
{
	if (k == KEY_UP || k == KEY_W)
		d->scene.player.ctrl.up_down = 1;
	else if (k == KEY_DOWN || k == KEY_S)
		d->scene.player.ctrl.up_down = -1;
	if (k == KEY_A)
		d->scene.player.ctrl.left_right = -1;
	else if (k == KEY_D)
		d->scene.player.ctrl.left_right = 1;
	if (k == KEY_LEFT)
		d->scene.player.ctrl.turn = -1;
	else if (k == KEY_RIGHT)
		d->scene.player.ctrl.turn = 1;

	if (k == KEY_ESCAPE)
		mlx_terminate(d);
	return (k);
}

int	key_up_hook(int k, t_cub *d)
{
	if (k == KEY_UP || k == KEY_DOWN || k == KEY_S || k == KEY_W)
		d->scene.player.ctrl.up_down = 0;
	if (k == KEY_A || k == KEY_D)
		d->scene.player.ctrl.left_right = 0;
	if (k == KEY_LEFT || k == KEY_RIGHT)
		d->scene.player.ctrl.turn = 0;
	return (k);
}
