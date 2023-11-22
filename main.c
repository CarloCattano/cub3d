/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:49:25 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
/*
int	mlx_terminate(t_cub *d)
{
	mlx_destroy_image(d->mlx, d->scr.img);
	mlx_destroy_window(d->mlx, d->scr.img);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	exit (0);
	return (0);
}

int	loop_hook(t_cub *c)
{
	cub_draw(c);
	return (0);
}
*/
/* 
	ply player
	wp weapon
	sc scene
	c cub
	screen scr
*/

int	main (int ac, char *av[])
{
	t_sc	sc;
	t_cub	c;

	if (ac != 2)
		return (cub_error(E_ARG, 1, NULL, NULL));
	if (cub_parser(av[1], &sc, &c))
		return (cub_error(E_PARS, 0, NULL, NULL));
	/*if (cub_init(&c, &sc))
		return (cub_error(E_IN, 0, NULL, NULL));	
	init_ply(&c);
	init_wp(&c);
	mlx_mouse_hide(c.mlx, c.win);
	//mlx_mouse_hook(c.scr.img, mouse_buttons, &c);
	mlx_hook(c.win, ON_WIN_ENTER, 1L<<4, entered, &c);
	mlx_hook(c.win, ON_WIN_LEAVE, 1L<<5, exited, &c);
	mlx_hook(c.win, ON_KEYDOWN, 1L << 0, key_down_hook, &c);
	mlx_hook(c.win, ON_KEYUP, 1L << 1, key_up_hook, &c); 
	mlx_hook(c.win, ON_MOUSEMOVE, 1 << 6, motion_hook, &c); 

	mlx_hook(c.win, ON_WINDOWCLOSE, 1L << 17, mlx_terminate, &c);
	mlx_loop_hook(c.mlx, loop_hook, &c);
	mlx_loop(c.mlx);
	mlx_terminate(&c);*/
	cub_freesc(&(sc), NULL);
	return (0);
}
