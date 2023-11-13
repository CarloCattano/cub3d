/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:22:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/12 16:38:12 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cub_init(t_cub *c, t_scene *sc)
{
	ft_bzero(c, sizeof(t_cub));
	c->scene = *sc;
/*	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3d");
	c->screen.img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->screen.pix = mlx_get_data_addr(c->screen.img, &c->screen.bpp, &c->screen.line_length, &c->screen.endian);	
	c->mini.img = mlx_new_image(c->mlx, MWIDTH, MHEIGHT);
	c->mini.pix = mlx_get_data_addr(c->mini.img, &c->mini.bpp, &c->mini.line_length, &c->mini.endian);	*/
	c->mini.h = MHEIGHT;
	c->mini.w = MWIDTH;	
	return (0);
}	


