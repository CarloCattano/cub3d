/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:34:17 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/04 12:09:42 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	key_hook(int k, t_3d *d)
{
	/* if (k == KEY_SPACE) */
	if (k == KEY_ESCAPE)
		terminate(d);
	return (k);
}
