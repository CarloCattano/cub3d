/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:27 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 00:27:07 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* TODO remove xoff/yoff if declare somewhere else */

int	cub_loadfile(t_image *i, void *mlx, char *path)
{
	i->img = mlx_xpm_file_to_image(mlx, path, &(i->w), &(i->h));
	if (!(i->img))
		return (1);
	i->pix = mlx_get_data_addr(i->img, &(i->bpp), &(i->ll), &(i->endian));
	if (!(i->pix))
		return (1);
	i->xoff =  1;
	i->yoff =  1;
	return (0);
}
