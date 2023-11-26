/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:41 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 23:53:46 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_loadply(t_load *load, t_ply *ply)
{
	ply->posx = *(load->xpl) + 0.5;
	ply->posy = *(load->ypl) + 0.5;
	if (load->dir == 'S')
	{
		ply->dirx = 0;
		ply->diry = 1;
	}
	if (load->dir == 'W')
	{
		ply->dirx = -1;
		ply->diry = 0;
	}
	if (load->dir == 'N')
	{
		ply->dirx = 0;
		ply->diry = -1;
	}
	if (load->dir == 'E')
	{
		ply->dirx = 1;
		ply->diry = 0;
	}
}
