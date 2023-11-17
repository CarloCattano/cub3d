/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadplayer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:41 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 19:22:35 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cub_loadplayer(t_load *load, t_player *player)
{
	player->posx = *(load->xpl); 
	player->posy = *(load->ypl);
	if (load->dir == 'S')
	{	
		player->dirX = 0;
		player->diry = 1;
	}	
	if (load->dir == 'W')
	{	
		player->dirX = -1;
		player->diry = 0;
	}	
	if (load->dir == 'N')
	{	
		player->dirX = 0;
		player->diry = -1;
	}	
	if (load->dir == 'E')
	{	
		player->dirX = 1;
		player->diry = 0;
	}
	printf("player->posx: %f\n", player->posx);
	printf("player->posy: %f\n", player->posy);
	return (0);
}
