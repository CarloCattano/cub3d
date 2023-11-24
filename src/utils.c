/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:11:48 by carlo             #+#    #+#             */
/*   Updated: 2023/11/24 21:12:45 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

u_int32_t	color_pixel(u_int32_t *pixel)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;

	if (pixel == NULL)
		return (0);
	r = (pixel[0] >> 24) & 0xFF;
	g = (pixel[0] >> 16) & 0xFF;
	b = (pixel[0] >> 8) & 0xFF;
	a = (pixel[0]) & 0xFF;
	return (((u_int32_t)r << 24) | ((u_int32_t)g << 16)
		| ((u_int32_t)b << 8) | (u_int32_t)a);
}
