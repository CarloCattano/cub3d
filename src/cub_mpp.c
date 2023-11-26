/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mpp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:12:25 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:41:24 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*(void)data;
	(void)x;
	(void)y;
	(void)color;
*/

void	cub_mpp(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pix + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
