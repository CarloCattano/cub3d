/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadcfpl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:09:54 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:56:51 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	cub_loadcfpl(t_sc *sc, t_load *load)
{
	sc->c_floor = *(load->floor);
	sc->c_ceiling = *(load->ceiling);
	sc->plane_x = -sc->ply.diry;
	sc->plane_y = sc->ply.dirX;
}
