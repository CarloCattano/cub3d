/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 12:10:00 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>



int	main (int ac, char *av[])
{
	t_scene sc;

	if (ac != 2)
		return (cub_error(ERROR_ARG, NULL, NULL));
	if (cub_parser(av[1]), &sc)
		return (cub_error(ERROR_PARS, NULL, NULL));
			

	
	return (0);
}
