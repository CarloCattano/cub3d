/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadplayer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:41 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 14:13:21 by jstrotbe         ###   ########.fr       */
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
		player->dirY = -1;
	}	
	if (load->dir == 'W')
	{	
		player->dirX = -1;
		player->dirY = 0;
	}	
	if (load->dir == 'N')
	{	
		player->dirX = 0;
		player->dirY = 1;
	}	
	if (load->dir == 'E')
	{	
		player->dirX = 1;
		player->dirY = 0;
	}	
	return (0);
}
