#include "../include/cub3d.h"

#define ROTATION_ANGLE 0.01f

static void draw_square(int x, int y, int w, int h, t_data *d);

#include <math.h>

void init_player(t_data *d) {
    d->player.pos.x = 300;
    d->player.pos.y = 300;

	d->player.dir.x = 0.2;
	d->player.dir.y = 0.5;

    d->player.speed = 1;
    d->player.ctrl.upDown = 0;
    d->player.ctrl.leftRight = 0;
	d->player.ctrl.turn = 0;
}

// cast ray from player position to the direction vector to 
// visualize the ray for the future raycasting algorithm
void castRay(t_data *d) {
	t_point p1;
	t_point p2;

	p1.x = d->player.pos.x;
	p1.y = d->player.pos.y;
	p2.x = d->player.pos.x + d->player.dir.x * 20;
	p2.y = d->player.pos.y + d->player.dir.y * 20;

	draw_line(d, p1, p2, 0x00FF00);
}

void movePlayer(t_data *d) 
{
    if (d->player.ctrl.upDown != 0) 
    {
        d->player.pos.x += d->player.dir.x * d->player.ctrl.upDown * d->player.speed;
        d->player.pos.y += d->player.dir.y * d->player.ctrl.upDown * d->player.speed;
		printf("dir.x: %f, dir.y: %f soeed %d updown %d\n", d->player.dir.x, d->player.dir.y, d->player.speed , d->player.ctrl.upDown);
    }

    if (d->player.ctrl.leftRight != 0) 
    {
        // Adjust movement for left and right input
        d->player.pos.x += d->player.dir.y * d->player.ctrl.leftRight * d->player.speed;
        d->player.pos.y -= d->player.dir.x * d->player.ctrl.leftRight * d->player.speed;
    }

    // Ensure the player stays within the window bounds
    d->player.pos.x = ft_clip(d->player.pos.x, 10, WIDTH - 20);
    d->player.pos.y = ft_clip(d->player.pos.y, 10, HEIGHT - 20);

	if (d->player.ctrl.turn != 0)
	{
		// Update the direction vector based on the turn input
		float angle = d->player.ctrl.turn * ROTATION_ANGLE;
		float newDirX = d->player.dir.x * cos(angle) - d->player.dir.y * sin(angle);
		float newDirY = d->player.dir.x * sin(angle) + d->player.dir.y * cos(angle);
		
		d->player.dir.x = newDirX;
		d->player.dir.y = newDirY;
		
		float length = sqrt(d->player.dir.x * d->player.dir.x + d->player.dir.y * d->player.dir.y);
		if (length != 0.0)
		{
			d->player.dir.x /= length;
			d->player.dir.y /= length;
		}
	}
}


void drawPlayer(t_data *d)
{
	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);

	movePlayer(d);
	castRay(d);
}

static void draw_square(int x, int y, int w, int h, t_data *d)
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
