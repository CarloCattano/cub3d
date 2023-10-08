
#include "../include/cub3d.h"

int	loop_hook(t_data *d)
{
	draw(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			d;

	if (!(init_variables(&d)) || ac != 2)
	{
		ft_putendl_fd("Failed to initialize variables", 1);
		terminate(&d);
	}
	ft_putendl_fd("Program initialized successfully", 1);
	ft_putendl_fd(av[1], 1);

	d.planeX = 0;
	d.planeY = 0.66;
	d.player.moveSpeed = 0.2;
	
	/* mlx_do_key_autorepeatoff(d.img.mlx); */
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
