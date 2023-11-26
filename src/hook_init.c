/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:36:45 by carlo             #+#    #+#             */
/*   Updated: 2023/11/26 22:39:26 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_cub *c)
{
	cub_draw(c);
	return (0);
}

void	init_hook(t_cub *c)
{
	mlx_mouse_hide(c->mlx, c->win);
	mlx_mouse_hook(c->win, mouse_buttons, c);
	mlx_hook(c->win, ON_WIN_ENTER, 1L << 4, entered, c);
	mlx_hook(c->win, ON_WIN_LEAVE, 1L << 5, exited, c);
	mlx_hook(c->win, ON_KEYDOWN, 1L << 0, key_down_hook, c);
	mlx_hook(c->win, ON_KEYUP, 1L << 1, key_up_hook, c);
	mlx_hook(c->win, ON_MOUSEMOVE, 1 << 6, motion_hook, c);
	mlx_hook(c->win, ON_WINDOWCLOSE, 1L << 17, mlx_terminate, c);
	mlx_loop_hook(c->mlx, loop_hook, c);
}
