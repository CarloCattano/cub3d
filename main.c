/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/13 21:23:27 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



int	main (int ac, char *av[])
{
	t_scene sc;
	t_cub	c;

	if (ac != 2)
		return (cub_error(ERROR_ARG, NULL, NULL));
	if (cub_parser(av[1], &sc, &c))
		return (cub_error(ERROR_PARS, NULL, NULL));
	if (cub_init(&c, &sc))
		return (cub_error(MAIN, NULL, NULL));	
	cub_draw(&c);
	cub_draw_minimap(&c);
	mlx_loop(c.mlx);	
	return (0);
}
