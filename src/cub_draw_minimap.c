/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 15:35:26 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pix + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}


void cub_draw_minimap(t_cub *c)
{
	my_mlx_pixel_put(&(c->mini) , MWIDTH / 2, MHEIGHT / 2,  0x00FF0000);
	mlx_put_image_to_window(c->mlx, c->win, c->mini.img, 0, 0);	


}
