/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:11:48 by carlo             #+#    #+#             */
/*   Updated: 2023/11/25 18:36:08 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clamp(int *color, u_int8_t min, u_int8_t max)
{
	if (*color < min)
		*color = min;
	else if (*color > max)
		*color = max;
}

u_int32_t cub_darken(u_int32_t argb, double factor)
{
 	int alpha = (argb >> 24) & 0xFF;
 	int red = (argb >> 16) & 0xFF;
 	int green = (argb >> 8) & 0xFF;
 	int blue = argb & 0xFF;

	factor = 1.0 - (factor / 20.0);
    red = red * factor;
    green = green * factor;
    blue = blue * factor;
	clamp(&red, 0, 255);
	clamp(&green, 0, 255);
	clamp(&blue, 0, 255);
	return (alpha << 24) | (red << 16) | (green << 8) | blue;

}
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
