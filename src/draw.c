#include "../include/fractol.h"
#include <mlx.h>
#include <time.h>

typedef struct s_2d
{
	unsigned int	x;
	unsigned int	y;
}					t_2d;

static void	my_mlx_pixel_put(t_3d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img.data + (y * d->img.sizeline + x * (d->img.bpp >> 3));
	*(unsigned int *)dst = color;
}

void	draw_line(t_3d *d, t_2d p1, t_2d p2, int color)
{
	int		i;
	t_2d	delta;
	t_2d	sign;
	t_2d	abs_delta;
	t_2d	current;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	
	abs_delta = delta;
	sign.x = delta.x > 0 ? 1 : -1;
	sign.y = delta.y > 0 ? 1 : -1;
	current = p1;
	i = 0;
	while (i <= ft_max(abs_delta.x, abs_delta.y))
	{
		my_mlx_pixel_put(d, current.x, current.y, color);
		current.x += sign.x;
		current.y += sign.y;
		i++;
	}
}


void clearCanvas(t_3d *d)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(d, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
}

static int	testCount = 0;

static int fps = 0;
static int fps_count = 0;
static time_t fps_time = 0;
static time_t fps_time2 = 0;
static char *fps_str = NULL;

static void	fps_counter(t_3d *d)
{
	fps_count++;
	fps_time2 = time(NULL);
	if (fps_time2 - fps_time >= 1)
	{
		fps = fps_count;
		fps_count = 0;
		fps_time = fps_time2;
	}

	if (fps_str)
		free(fps_str);
	fps_str = ft_itoa(fps);
	mlx_string_put(d->img.mlx, d->img.win, 4, 10, 0xFFAAFF, "FPS: ");
	mlx_string_put(d->img.mlx, d->img.win, 34, 10, 0xFFFFFF, fps_str);
}

void draw(t_3d *d)
{
	t_2d	p1;
	t_2d	p2;
	int		color;

	if (testCount < HEIGHT - 10)
		testCount++;
	else if(testCount >= HEIGHT - 10)
		testCount = 1;
	
	color = 0x00FF00;
	p1.x = WIDTH >> 1;
	p1.y = HEIGHT >> 1;
	p2.x = 0;
	p2.y = testCount;
	
	clearCanvas(d);

	draw_line(d, p1, p2, color);
	
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
	fps_counter(d);
}


