/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mpp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:12:25 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/11 16:13:21 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void	cub_mpp(t_image *data, int x, int y, int color)
{
	/*(void)data;
	(void)x;
	(void)y;
	(void)color;*/
	char	*dst;

	dst = data->pix + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
