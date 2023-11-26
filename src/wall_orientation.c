/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:46:33 by carlo             #+#    #+#             */
/*   Updated: 2023/11/26 14:11:40 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_orientation(t_ray *ray, t_cub *c, t_fp *fp)
{
	if (ray->s == 0 && ray->rdx > 0)
		fp->tex = &(c->sc.wall[3]);
	else if (ray->s == 0 && ray->rdx < 0)
		fp->tex = &(c->sc.wall[2]);
	else if (ray->s == 1 && ray->rdy > 0)
		fp->tex = &(c->sc.wall[1]);
	else if (ray->s == 1 && ray->rdy < 0)
		fp->tex = &(c->sc.wall[0]);
	else
		(void)fp;
}
