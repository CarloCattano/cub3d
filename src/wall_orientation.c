/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:46:33 by carlo             #+#    #+#             */
/*   Updated: 2023/11/22 00:04:58 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** 
 * @brief
 * 		Assigns the texture to the wall depending on the ray side and ray direction.
 * 		0 = north, 1 = south, 2 = east, 3 = west
 * 		hardcoded to match the order of the textures in the struct
 * @param
 * 		ray: the ray struct
 * 		c: the cub struct
 * 		fp: the fp struct
*/

void	get_wall_orientation(t_ray *ray, t_cub *c, t_fp *fp)
{
	if (ray->side == 0 && ray->raydirX > 0)
		fp->tex = &(c->sc.wall[2]);
	else if (ray->side == 0 && ray->raydirX < 0)
		fp->tex = &(c->sc.wall[3]);
	else if (ray->side == 1 && ray->raydiry > 0)
		fp->tex = &(c->sc.wall[1]);
	else if (ray->side == 1 && ray->raydiry < 0)
		fp->tex = &(c->sc.wall[0]);
	else
		(void)fp;
}
