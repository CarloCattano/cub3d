/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:34:17 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/05 00:24:24 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "key_codes.h"

/* static void	set_color(int k, t_3d *d) */
/* { */
/* 	if (k >= KEY_PAD_0 && k <= KEY_PAD_7) */
/* 	{ */
/* 		if (k == KEY_PAD_1) */
/* 			d->color = 1; */
/* 		else if (k == KEY_PAD_2) */
/* 			d->color = 2; */
/* 		else if (k == KEY_PAD_3) */
/* 			d->color = 3; */
/* 		else if (k == KEY_PAD_4) */
/* 			d->color = 4; */
/* 		else if (k == KEY_PAD_5) */
/* 			d->color = 5; */
/* 	} */
/* } */

int	key_down_hook(int k, t_3d *d)
{
	
	/* float turnSpeed; */

	/* turnSpeed = 0.1; */

	if (k == KEY_UP)
	{
		/* d->player.pos.y += d->player.dir.y * d->player.speed; */
		/* d->player.pos.x += d->player.dir.x * d->player.speed; */
		d->player.ctrl.upDown = 1;
	}
	if (k == KEY_DOWN)
	{
		/* d->player.pos.y -= d->player.dir.y * d->player.speed; */
		/* d->player.pos.x -= d->player.dir.x * d->player.speed; */
		d->player.ctrl.upDown = -1;
	}
	if (k == KEY_LEFT)
	{
		/* d->player.dir.x = d->player.dir.x * cos(turnSpeed) - d->player.dir.y * sin(turnSpeed); */
		/* d->player.dir.y = d->player.dir.x * sin(turnSpeed) + d->player.dir.y * cos(turnSpeed); */
		d->player.ctrl.leftRight = -1;
	}

	if (k == KEY_RIGHT)
	{
		/* d->player.dir.x = d->player.dir.x * cos(-turnSpeed) - d->player.dir.y * sin(-turnSpeed); */
		/* d->player.dir.y = d->player.dir.x * sin(-turnSpeed) + d->player.dir.y * cos(-turnSpeed); */
		d->player.ctrl.leftRight = 1;
	}

	
	if (k == KEY_ESCAPE)
		terminate(d);
	return (k);
}

int key_up_hook(int k, t_3d *d)
{
	ft_printf("key up: %d\n", k);
	if (k != KEY_UP && k != KEY_DOWN)
		d->player.ctrl.upDown = 0;
	if (k != KEY_LEFT && k != KEY_RIGHT)
		d->player.ctrl.leftRight = 0;

	return (k);
}
