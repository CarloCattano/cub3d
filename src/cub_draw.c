/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:50 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 16:29:06 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void cub_draw(t_cub *c)
{
	int x;
	int y;

	y = -1;
		
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
				cub_mpp(&(c->screen), x, y, c->scene.c_floor);
		}
	}
//	 mlx_put_image_to_window(c->mlx, c->win, c->screen.img, 0, 0);
}
