/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:38:02 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/03 11:28:53 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	init_variables(t_3d *d);
static int	init_fractal(t_3d *d);

/* static void	draw_fractal(t_3d *d) */
/* my_mlx_pixel_put(d, d->i.x, d->i.y, (int)color_pixel(d, i)); */


/*
	Initialize image
*/

void	init_img(t_3d *d)
{
	int	bpp;
	int	sizeline;
	int	endian;

	d->img.image = mlx_new_image(d->img.mlx, WIDTH, HEIGHT);
	d->img.data = mlx_get_data_addr(d->img.image, &bpp, &sizeline, &endian);
	d->img.bpp = bpp;
	d->img.sizeline = sizeline;
	d->img.endian = endian;
}

/* static void	my_mlx_pixel_put(t_3d *d, int x, int y, int color) */
/* { */
/* 	char	*dst; */

/* 	dst = d->img.data + (y * d->img.sizeline + x * (d->img.bpp >> 3)); */
/* 	*(unsigned int *)dst = color; */
/* } */

int	terminate(t_3d *d)
{
	mlx_destroy_image(d->img.mlx, d->img.image);
	mlx_destroy_window(d->img.mlx, d->img.win);
	mlx_destroy_display(d->img.mlx);
	free(d->img.mlx);
	ft_putendl_fd("Program terminated Gracefully ❤️", 1);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_3d	d;
	(void)ac;
	(void)av;
	/* if (ac < 2 || ac >= 4 || !init_fractal(&d, av[1], av[2])) */
	/* { */
	/* 	ft_putendl_fd("some error", 1); */
	/* 	exit(-1); */
	/* } */
	/* else if (!(init_variables(&d))) */
	/* 	ft_putendl_fd("Failed to initialize variables", 1); */

	//fractol(&d);

	if (!(init_variables(&d)))
	{
		ft_putendl_fd("Failed to initialize variables", 1);
		terminate(&d);
	}
	if(!init_fractal(&d))
	{
		ft_putendl_fd("some error", 1);
		terminate(&d);
	}	
	mlx_mouse_hook(d.img.win, mouse_scaling_hook, &d);
	mlx_hook(d.img.win, ON_KEYDOWN, 1L << 0, key_hook, &d);
	mlx_hook(d.img.win, ON_MOUSEMOVE, 1 << 6, motion_hook, &d);
	mlx_hook(d.img.win, ON_WINDOWCLOSE, 1L << 17, terminate, &d);
	mlx_loop(d.img.mlx);
	terminate(&d);
	return (0);
}

static int	init_variables(t_3d *d)
{
	d->img.mlx = mlx_init();
	d->img.win = mlx_new_window(d->img.mlx, WIDTH, HEIGHT, "Fractol");
	
	if (!(d->img.mlx))
		ft_putendl_fd("failed to init mlx", 1);
	if (!(d->img.win))
		ft_putendl_fd("Error creating window", 1);
	
	init_img(d);
	
	if (!d->img.image)
		ft_putendl_fd("Error creating image", 1);
	d->menu = 0;
	return (1);
}

static int	init_fractal(t_3d *d)
{
	(void)d;
	return (1);
}
