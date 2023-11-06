/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/06 13:43:05 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>



int	main (int ac, char *av[])
{
	if (ac != 2)
		return (cub_error(ERROR_ARG, NULL, NULL));
	if (cub_parser(av[1]))
		return (cub_error(ERROR_PARS, NULL, NULL));
			

	
	return (0);
}
