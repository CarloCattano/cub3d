
#include "../include/cub3d.h"

static void draw_square(int x, int y, int w, int h, t_3d *d);

void init_player(t_player *player)
{
    player->pos.x = 42;
    player->pos.y = 42;
    player->dir.x = -1;
    player->dir.y = 0;
}

void drawPlayer(t_3d *d)
{
    t_2d p1;
    t_2d p2;

    p1.x = d->player.pos.x;
    p1.y = d->player.pos.y;
    p2.x = d->player.pos.x + d->player.dir.x * 10;
    p2.y = d->player.pos.y + d->player.dir.y * 10;

    (void)p1;
    (void)p2;
    // draw a square at the player position
    draw_square(d->player.pos.x - 5, d->player.pos.y - 5, 10, 10, d);
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