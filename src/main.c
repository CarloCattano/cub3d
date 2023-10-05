
#include "../include/cub3d.h"

static int	init_variables(t_3d *d);

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

int loop_hook(t_3d *d)
{
	draw(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_3d			d;
	(void)ac;
	(void)av;
	
	if (!(init_variables(&d)))
	{
		ft_putendl_fd("Failed to initialize variables", 1);
		terminate(&d);
	}
	
	mlx_do_key_autorepeatoff(d.img.mlx); // does it work?
	mlx_mouse_hook(d.img.win, mouse_scaling_hook, &d);
	mlx_hook(d.img.win, ON_KEYDOWN, 1L << 0, key_down_hook, &d);
	mlx_hook(d.img.win, ON_KEYUP, 1L << 1, key_up_hook, &d);
	mlx_hook(d.img.win, ON_MOUSEMOVE, 1 << 6, motion_hook, &d);
	mlx_hook(d.img.win, ON_WINDOWCLOSE, 1L << 17, terminate, &d);
	mlx_loop_hook(d.img.mlx, loop_hook, &d);
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
	init_player(d);

	if (!d->img.image)
		ft_putendl_fd("Error creating image", 1);
	d->menu = 0;
	return (1);
}
