/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:05:07 by ccattano          #+#    #+#             */
/*   Updated: 2023/02/13 17:28:00 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	julia_variations(t_3d *d);

/*
 	https://en.wikipedia.org/wiki/Julia_set
	
	f(z) = z^2 + c
*/
void	julia(t_3d *d, t_cnb z, int *i)
{
	double	t;

	t = 0;
	while (++(*i) < d->max && z.r * z.r + z.i * z.i < 4)
	{
		t = z.r;
		z.r = t * t - z.i * z.i + d->julia.r;
		z.i = 2 * z.i * t + d->julia.i;
	}
}

void	init_julia_set(t_3d *d)
{
	if (d->fractal == JULIA)
	{
		d->zoom = 200;
		d->max = 10;
		julia_variations(d);
	}
}

/*
	julia sets
	https://en.wikipedia.org/wiki/Julia_set
*/

static void	julia_variations(t_3d *d)
{
	if (!d->rng)
		d->julia = (t_cnb){.r = -0.506667, .i = 0.520000};
	else if (d->rng == 1)
		d->julia = (t_cnb){.r = 0.4, .i = 0.6};
	else if (d->rng == 2)
		d->julia = (t_cnb){.r = -0.8, .i = 0.156};
	else if (d->rng == 3)
		d->julia = (t_cnb){.r = -0.835, .i = -0.2321};
	else if (d->rng == 4)
		d->julia = (t_cnb){.r = 0.285, .i = 0.01};
	else if (d->rng == 5)
		d->julia = (t_cnb){.r = -0.7269, .i = 0.1889};
	else
		d->julia = (t_cnb){.r = 0.424242, .i = 0.424242};
}
/*
	https://en.wikipedia.org/wiki/Mandelbrot_set
	https://rosettacode.org/wiki/Mandelbrot_set
*/

void	mandelbrot(t_3d *d, t_cnb z, t_cnb c, int *i)
{
	double	n;
	double	t;

	n = z.r * z.r + z.i * z.i;
	t = 0;
	while (++(*i) < d->max && n < 4)
	{
		t = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * t + c.i;
		n = pow(z.r, 2) + pow(z.i, 2);
	}
}

/* 
	convert z.r to any power
	xatmp=(x*x+y*y)^(n/2) *cos(n*atan2(y,x)) + a
	y=(x*x+y*y)^(n/2)*sin(n*atan2(y,x)) + b
	x=xtmp
*/

void	mandelbrot2(t_3d *d, t_cnb z, t_cnb c, int *i)
{
	double	n;
	double	t;

	t = 0;
	n = pow(z.r, 2) + pow(z.i, 2);
	while (++(*i) < d->max && n < 4)
	{	
		t = z.r;
		z.r = pow(z.r * z.r + z.i * z.i, d->exp / 2) \
			* cos(d->exp * atan2(z.i, z.r)) + c.r;
		z.i = pow(t * t + z.i * z.i, d->exp / 2) \
			* sin(d->exp * atan2(z.i, t)) + c.i;
		n = pow(z.r, 2) + pow(z.i, 2);
	}
}
