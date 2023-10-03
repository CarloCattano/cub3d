#include "../include/fractol.h"

static void	my_mlx_pixel_put(t_3d *d, int x, int y, int color);
static void	draw_fractal(t_3d *d);

void	fractol(t_3d *d)
{
	d->min.x = ((d->offset.x + (WIDTH >> 1)) / (d->zoom / 2)) / -2;
	d->min.y = ((d->offset.y + (HEIGHT >> 1)) / (d->zoom / 2)) / -2;
	d->i.y = 0;
	while (d->i.y < HEIGHT)
	{
		d->i.x = -1;
		while (++d->i.x < WIDTH)
			draw_fractal(d);
		++d->i.y;
	}
	mlx_clear_window(d->img.mlx, d->img.win);
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
	if (d->menu)
		settings(d);
	if (d->exp > 16)
		d->exp = 2;
}


