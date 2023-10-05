
#include "../include/cub3d.h"

static void draw_square(int x, int y, int w, int h, t_3d *d);

void init_player(t_3d *d)
{
	d->player.pos.x = 42;
	d->player.pos.y = 42;
	d->player.dir.x = 1;
	d->player.dir.y = 0;
	d->player.speed = 1;
	d->player.ctrl.upDown = 0;
	d->player.ctrl.leftRight = 0;
}

int angleVector(t_3d *d)
{
	float angle;
	
	angle = atan2(d->player.dir.y, d->player.dir.x);
	return ((int)angle);
}

void draw_line_angle(t_3d *d, int angle)
{
	t_point origin;
	t_point p2;
	
	origin.x = d->player.pos.x;
	origin.y = d->player.pos.y;

	p2.x = d->player.pos.x + (cos(angle) * 20.0f);
	p2.y = d->player.pos.y + (sin(angle) * 20.0f);
	draw_line(d, origin, p2, 0xFF0000);
}

void draw_direction(t_3d *d)
{
	draw_line_angle(d, angleVector(d));
}

void movePlayer(t_3d *d)
{
	float turnSpeed;
	turnSpeed = 0.05;

	if (d->player.ctrl.upDown == 1)
	{
		d->player.pos.y += d->player.dir.y * d->player.speed;
		d->player.pos.x += d->player.dir.x * d->player.speed;
	}
	else if (d->player.ctrl.upDown == -1 )
	{
		d->player.pos.y -= d->player.dir.y * d->player.speed;
		d->player.pos.x -= d->player.dir.x * d->player.speed;
	}
	
	if (d->player.ctrl.leftRight == 1)
	{
		d->player.dir.x = d->player.dir.x * cos(turnSpeed) - d->player.dir.y * sin(turnSpeed);
		d->player.dir.y = d->player.dir.x * sin(turnSpeed) + d->player.dir.y * cos(turnSpeed);
	}
	else if (d->player.ctrl.leftRight == -1)
	{
		d->player.dir.x = d->player.dir.x * cos(-turnSpeed) - d->player.dir.y * sin(-turnSpeed);
		d->player.dir.y = d->player.dir.x * sin(-turnSpeed) + d->player.dir.y * cos(-turnSpeed);
	}
}

void drawPlayer(t_3d *d)
{
	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);
	draw_direction(d);
	movePlayer(d);
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
