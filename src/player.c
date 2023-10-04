
#include "../include/cub3d.h"

static void draw_square(int x, int y, int w, int h, t_3d *d);

void init_player(t_3d *d)
{
	d->player.pos.x = 42;
	d->player.pos.y = 42;
	d->player.dir.x = 1;
	d->player.dir.y = 1;
	d->player.speed = 1;
	d->player.ctrl.upDown = 0;
	d->player.ctrl.leftRight = 0;
}
void draw_direction(t_3d *d)
{
	t_point origin;
	t_point p2;
	
	origin.x = d->player.pos.x;
	origin.y = d->player.pos.y;

	p2.x = d->player.pos.x + d->player.dir.x * 10;
	p2.y = d->player.pos.y + d->player.dir.y * 10;
	draw_line(d, origin, p2, 0xFF0000);

}

void movePlayer(t_3d *d)
{

	// check for bounds
	int canMove = d->player.pos.x > 1 && d->player.pos.x < WIDTH-4 && d->player.pos.y > 0 && d->player.pos.y < HEIGHT ? 1 : 0;

	if (d->player.ctrl.upDown == 1 && canMove)
	{
		d->player.pos.y += d->player.dir.y * d->player.speed;
		d->player.pos.x += d->player.dir.x * d->player.speed;
	}
	if (d->player.ctrl.upDown == -1 && canMove)
	{
		d->player.pos.y -= d->player.dir.y * d->player.speed;
		d->player.pos.x -= d->player.dir.x * d->player.speed;
	}
	if (d->player.ctrl.leftRight == -1)
	{
		d->player.dir.x = d->player.dir.x * cos(0.1) - d->player.dir.y * sin(0.1);
		d->player.dir.y = d->player.dir.x * sin(0.1) + d->player.dir.y * cos(0.1);
	}
	if (d->player.ctrl.leftRight == 1)
	{
		d->player.dir.x = d->player.dir.x * cos(-0.1) - d->player.dir.y * sin(-0.1);
		d->player.dir.y = d->player.dir.x * sin(-0.1) + d->player.dir.y * cos(-0.1);
	}
}

void drawPlayer(t_3d *d)
{
	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);
	draw_direction(d);
	movePlayer(d);
}


static void	my_mlx_pixel_put(t_3d *d, int x, int y, int color)
{
    char	*dst;

    dst = d->img.data + (y * d->img.sizeline + x * (d->img.bpp >> 3));
    *(unsigned int *)dst = color;
}

static void draw_square(int x, int y, int w, int h, t_3d *d)
{
    int i;
    int j;

    i = 0;
    while (i < w)
    {
        j = 0;
        while (j < h)
        {
            my_mlx_pixel_put(d, x + i, y + j, 0x00FF00);
            j++;
        }
        i++;
    }
}
