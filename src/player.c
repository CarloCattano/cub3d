#include "../include/cub3d.h"

#define ROTATION_ANGLE 0.01f

static void draw_square(int x, int y, int w, int h, t_data *d);

#include <math.h>

void init_player(t_data *d) {
    d->player.pos.x = 300;
    d->player.pos.y = 300;

    // Initialize the direction vector (assuming an initial rightward direction)
    d->player.dir.x = 1.0;
    d->player.dir.y = 1.0;

    // Normalize the direction vector
    float length = sqrt(d->player.dir.x * d->player.dir.x + d->player.dir.y * d->player.dir.y);
    if (length != 0.0) {
        d->player.dir.x /= length;
        d->player.dir.y /= length;
    }

    d->player.speed = 1;
    d->player.ctrl.upDown = 0;
    d->player.ctrl.leftRight = 0;
}

float angleVector(t_data *d)
{
    return atan2(d->player.dir.y, d->player.dir.x);
}

void draw_line_angle(t_data *d, float angle)
{
	t_point origin;
    t_point p2;

    origin.x = d->player.pos.x;
    origin.y = d->player.pos.y;

    // Calculate the endpoint based on the angle in radians
    p2.x = origin.x + (cos(angle) * 20.0f);
    p2.y = origin.y + (sin(angle) * 20.0f);

    draw_line(d, origin, p2, 0x00FF00);
}

void rotatePlayerDirection(t_data *d, float angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);

    float oldDirX = d->player.dir.x;
    d->player.dir.x = oldDirX * cosAngle - d->player.dir.y * sinAngle;
    d->player.dir.y = oldDirX * sinAngle + d->player.dir.y * cosAngle;
}
void movePlayer(t_data *d) 
{
    float movementX = 0.0f;
    float movementY = 0.0f;

    // Calculate movement based on direction and input
    if (d->player.ctrl.upDown == 1) {
        movementX = d->player.dir.x * d->player.speed;
        movementY = d->player.dir.y * d->player.speed;
    } else if (d->player.ctrl.upDown == -1) {
        movementX = -d->player.dir.x * d->player.speed;
        movementY = -d->player.dir.y * d->player.speed;
	}

    // Update player position
    d->player.pos.x += movementX;
    d->player.pos.y += movementY;

    // Rotation based on left and right input
    if (d->player.ctrl.leftRight == 1) {
        rotatePlayerDirection(d, ROTATION_ANGLE);
    } else if (d->player.ctrl.leftRight == -1) {
        rotatePlayerDirection(d, -ROTATION_ANGLE);
    }
    //printf("dir.x: %f, dir.y: %f\n", d->player.dir.x, d->player.dir.y);
}

void drawPlayer(t_data *d)
{
	draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);
    t_point p2;
    p2.x = d->player.pos.x + (d->player.dir.x * 20.0f);
    p2.y = d->player.pos.y + (d->player.dir.y * 20.0f);
    // Draw the direction line with constant length
    draw_line(d, d->player.pos, p2, 0x00FF00);
	movePlayer(d);
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
