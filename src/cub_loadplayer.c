/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadplayer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:41 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 15:03:28 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cub_loadplayer(t_load *load, t_player *player)
{
	player->posX = *(load->xpl); 
	player->posY = *(load->ypl);
	if (load->dir == 'S')
	{	
		player->dirX = 0;
		player->dirY = 1;
	}	
	if (load->dir == 'W')
	{	
		player->dirX = -1;
		player->dirY = 0;
	}	
	if (load->dir == 'N')
	{	
		player->dirX = 0;
		player->dirY = -1;
	}	
	if (load->dir == 'E')
	{	
		player->dirX = 1;
		player->dirY = 0;
	}
	printf("player->posX: %f\n", player->posX);
	printf("player->posY: %f\n", player->posY);
	return (0);
}
