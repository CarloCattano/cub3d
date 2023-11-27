/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_open_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:04:40 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/27 13:06:40 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* first steps
	- look if a door is in front of you;
		- postion if the player next cube +1 is door 
	- set value to 0;				

*/

void	ft_check(t_cub *c, int x, int y)
{
	if (x > 2 || y > 2)
		return ;
	if (c->sc.map.val[(int)(c->sc.ply.posy + y)][(int)(c->sc.ply.posx + x)]
		== '1')
		return ;
	if (c->sc.map.val[(int)(c->sc.ply.posy + y)][(int)(c->sc.ply.posx + x)]
		== 'D')
	{
		c->sc.map.val[(int)(c->sc.ply.posy + y)][(int)(c->sc.ply.posx + x)]
			= '0';
		return ;
	}
	if (x > 0)
		ft_check(c, x + 1, y);
	if (y > 0)
		ft_check(c, x, y + 1);
	if (x < 0)
		ft_check(c, x - 1, y);
	if (y < 0)
		ft_check(c, x, y - 1);
}

void	cub_open_door(t_cub *c)
{
	if (c->sc.ply.dirx <= 0 && c->sc.ply.diry <= 0)
		ft_check(c, 0, -1);
	if (c->sc.ply.dirx >= 0 && c->sc.ply.diry <= 0)
		ft_check(c, 1, 0);
	if (c->sc.ply.dirx <= 0 && c->sc.ply.diry >= 0)
		ft_check(c, -1, 0);
	if (c->sc.ply.dirx >= 0 && c->sc.ply.diry >= 0)
		ft_check(c, 0, 1);
}
