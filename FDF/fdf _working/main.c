/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:29:03 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 16:49:05 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		fdf_exit_error(ERR_ARGS, 0);
	fdf_load_map(argv[1], &fdf);
	fdf_start(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
