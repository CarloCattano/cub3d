/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_cub *c)
{
	cub_draw(c);
	return (0);
}

int	main(int ac, char *av[])
{
	t_sc	sc;
	t_cub	c;

	if (ac != 2)
		return (cub_error(E_ARG, 1, NULL, NULL));
	if (cub_parser(av[1], &sc, &c))
	{
		cub_error(E_PARS, 0, NULL, NULL);
		mlx_terminate(&c);
	}
	if (cub_init(&c, &sc))
		return (cub_error(E_IN, 0, NULL, NULL));
	mlx_mouse_hide(c.mlx, c.win);
	mlx_mouse_hook(c.win, mouse_buttons, &c);
	mlx_hook(c.win, ON_WIN_ENTER, 1L << 4, entered, &c);
	mlx_hook(c.win, ON_WIN_LEAVE, 1L << 5, exited, &c);
	mlx_hook(c.win, ON_KEYDOWN, 1L << 0, key_down_hook, &c);
	mlx_hook(c.win, ON_KEYUP, 1L << 1, key_up_hook, &c);
	mlx_hook(c.win, ON_MOUSEMOVE, 1 << 6, motion_hook, &c);
	mlx_hook(c.win, ON_WINDOWCLOSE, 1L << 17, mlx_terminate, &c);
	mlx_loop_hook(c.mlx, loop_hook, &c);
	mlx_loop(c.mlx);
	mlx_terminate(&c);
	return (0);
}
