/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:27 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/14 14:57:14 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		cub_loadfile(t_imgage *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &(img->w), &(img->h));
	if (!(img->img))
		return (1);
	img->pix = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_length), &(img->endian));
	if (!(img->pix))
		return ( 1);
	img->xoff = img->x / (double)TX;
	img->yoff = img->y / (double)TY; 
	return (0);
}  		
