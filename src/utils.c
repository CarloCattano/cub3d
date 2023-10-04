/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:37:47 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/04 10:19:20 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

