/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:37:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/08 23:40:55 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_clip(int n, int min, int max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}

int	ft_rgb2hex(t_rgb rgb)
{
	int	hex;

	hex = ((int)rgb.r << 16) + ((int)rgb.g << 8) + rgb.b;
	return (hex);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img.data + (y * d->img.sizeline + x * (d->img.bpp >> 3));
	*(unsigned int *)dst = color;
}
