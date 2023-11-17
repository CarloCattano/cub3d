#include "cube3d.h"

void init_weapon(t_cub *d)
{
	d->scene.player.weapon.path = "./res/gun3.xpm";
	d->scene.player.weapon.img.img = mlx_xpm_file_to_image(d->mlx, d->scene.player.weapon.path, &d->scene.player.weapon.img.x, &d->scene.player.weapon.img.y);
	d->scene.player.weapon.img.pix = mlx_get_data_addr(d->scene.player.weapon.img.img, &d->scene.player.weapon.img.bpp, &d->scene.player.weapon.img.line_lenght, &d->scene.player.weapon.img.endian);
}

u_int32_t	color_pixel(u_int32_t *pixel)
{
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;
	u_int8_t	alpha;

	if (pixel == NULL)
		return (0);
	red = (pixel[0] >> 24) & 0xFF;
	green = (pixel[0] >> 16) & 0xFF;
	blue = (pixel[0] >> 8) & 0xFF;
	alpha = (pixel[0]) & 0xFF;
	return (((u_int32_t)red << 24) | ((u_int32_t)green << 16)
		| ((u_int32_t)blue << 8) | (u_int32_t)alpha);
}

void	put_weapon(t_cub *d, int x, int y, int color)
{
	char	*dst;
	dst = d->img.pix + ((y + 550) * d->img.line_lenght + (x + 200) * (d->img.bpp >> 3));
	*(unsigned int *)dst = color;
}

void	draw_weapon(t_cub *d)
{
	int				x;
	int				y;
	int				color;

	x = 0;
	while (x < d->scene.player.weapon.img.x)
	{
		y = 0;
		while (y < d->scene.player.weapon.img.y)
		{
			int index = (y * d->scene.player.weapon.img.line_lenght + x * (d->scene.player.weapon.img.bpp >> 3));
			color = color_pixel((u_int32_t *)&(d->scene.player.weapon.img.pix[index]));
			if ( color != (int)0xFF000000) 
				put_weapon(d, x, y, color);
			y++;
		}
		x++;
	}
}
