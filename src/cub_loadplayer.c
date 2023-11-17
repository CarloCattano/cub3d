/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:41 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 19:22:35 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cub_loadply(t_load *load, t_ply *ply)
{
	ply->posx = *(load->xpl); 
	ply->posy = *(load->ypl);
	if (load->dir == 'S')
	{	
		ply->dirX = 0;
		ply->diry = 1;
	}	
	if (load->dir == 'W')
	{	
		ply->dirX = -1;
		ply->diry = 0;
	}	
	if (load->dir == 'N')
	{	
		ply->dirX = 0;
		ply->diry = -1;
	}	
	if (load->dir == 'E')
	{	
		ply->dirX = 1;
		ply->diry = 0;
	}
	printf("ply->posx: %f\n", ply->posx);
	printf("ply->posy: %f\n", ply->posy);
	return (0);
}
