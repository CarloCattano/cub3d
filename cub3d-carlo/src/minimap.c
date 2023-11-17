/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:10:18 by ccattano          #+#    #+#             */
/*   Updated: 2023/11/06 15:00:02 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_square(int x, int y, int w, int h, t_data *d);
void draw_ray(t_data *d, int x, int y, double dirX, double dirY, int color);


void	draw_minimap(t_data *d)
{
	double scaled = 180.0 / MAPWIDTH;
	double posX = d->player.posX * scaled;
	double posY = d->player.posY * scaled;

	ft_bzero(d->mmap.pix, 180 * 180 * (d->mmap.bpp / 8));
	draw_square(posX, posY, 10, 10, d);
	draw_ray(d, posX, posY, d->player.dirX, d->player.dirY, 0x00FF0000);
	mlx_put_image_to_window(d->mlx, d->win, d->mmap.img, 0, 0);
}


void	put_minimap(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mmap.pix + (y * d->mmap.line_lenght + x * (d->mmap.bpp >> 3));
	*(unsigned int *)dst = color;
}

static void	draw_square(int x, int y, int w, int h, t_data *d)
{
	int	j;
	int	i;

	i = 0;
	while (i++ < w)
	{
		j = 0;
		while (j++ < h)
			put_minimap(d, x + i, y + j, 0xFFFF0000);
		i++;
	}
}

void draw_ray(t_data *d, int x, int y, double dirX, double dirY, int color)
{
    double posX = x;
    double posY = y;
    double rayX = posX + dirX;
    double rayY = posY + dirY;
    
    // Draw for center
    put_minimap(d, rayX, rayY, color);

    // Draw for left angle of FOV
    double leftDirX = dirX * cos(-FOV / 2) - dirY * sin(-FOV / 2);
    double leftDirY = dirX * sin(-FOV / 2) + dirY * cos(-FOV / 2);
    put_minimap(d, rayX + leftDirX, rayY + leftDirY, color);

    // Draw for right angle of FOV
    double rightDirX = dirX * cos(FOV / 2) - dirY * sin(FOV / 2);
    double rightDirY = dirX * sin(FOV / 2) + dirY * cos(FOV / 2);
    put_minimap(d, rayX + rightDirX, rayY + rightDirY, color);

}