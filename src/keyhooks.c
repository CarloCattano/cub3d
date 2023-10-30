/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:32 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/30 13:09:39 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/key_codes.h"

int	key_down_hook(int k, t_data *d)
{
	if (k == KEY_UP)
		d->player.ctrl.up_down = 1;
	else if (k == KEY_DOWN)
		d->player.ctrl.up_down = -1;
	if (k == KEY_A)
		d->player.ctrl.left_right = -1;
	else if (k == KEY_D)
		d->player.ctrl.left_right = 1;
	if (k == KEY_LEFT)
		d->player.ctrl.turn = -1;
	else if (k == KEY_RIGHT)
		d->player.ctrl.turn = 1;

	if (k == KEY_ESCAPE)
		terminate(d);
	return (k);
}

int	key_up_hook(int k, t_data *d)
{
	if (k == KEY_UP || k == KEY_DOWN)
		d->player.ctrl.up_down = 0;
	if (k == KEY_A || k == KEY_D)
		d->player.ctrl.left_right = 0;
	if (k == KEY_LEFT || k == KEY_RIGHT)
		d->player.ctrl.turn = 0;
	return (k);
}