/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:27 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_loadfile(t_image *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &(img->w), &(img->h));
	if (!(img->img))
		return (1);
	img->pix = mlx_get_data_addr(img->img, &(img->bpp), &(img->ll), &(img->endian));
	if (!(img->pix))
		return ( 1);
	img->xoff = img->w / (double)TX;
	img->yoff = img->h / (double)TY;
	return (0);
}  		
