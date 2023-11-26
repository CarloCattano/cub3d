/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 22:34:07 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_sc	sc;
	t_cub	c;

	if (ac != 2)
		return (cub_error(E_ARG, 1, NULL, NULL));
	ft_bzero(&c, sizeof(t_cub));
	ft_bzero(&sc, sizeof(t_sc));
	if (cub_parser(av[1], &sc, &c))
		return (cub_error(E_PARS, 0, (void *)mlx_terminate, &c));
	if (cub_init(&c, &sc))
		return (cub_error(E_IN, 0, (void *)mlx_terminate, &c));
	mlx_loop(c.mlx);
	return (0);
}
