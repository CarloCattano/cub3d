/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_animate_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:13:23 by carlo             #+#    #+#             */
/*   Updated: 2023/11/25 17:43:08 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wp_sprites(t_cub *c)
{
	char	*paths[9];
	int		i;

	paths[0] = "./res/gun/gun.xpm";
	paths[1] = "./res/gun/gun1.xpm";
	paths[2] = "./res/gun/gun2.xpm";
	paths[3] = "./res/gun/gun3.xpm";
	paths[4] = "./res/gun/gun4.xpm";
	paths[5] = "./res/gun/gun5.xpm";
	paths[6] = "./res/gun/gun6.xpm";
	paths[7] = "./res/gun/gun7.xpm";
	paths[8] = "./res/gun/gun8.xpm";
	i = 0;
	while (i < 9)
	{
		c->sc.ply.sprites[i].path = paths[i];
		c->sc.ply.sprites[i].img = malloc(sizeof(t_image));
		c->sc.ply.sprites[i].img->img = mlx_xpm_file_to_image(c->mlx,
				c->sc.ply.sprites[i].path, &c->sc.ply.sprites[i].img->w,
				&c->sc.ply.sprites[i].img->h);
		c->sc.ply.sprites[i].img->pix = mlx_get_data_addr(c->sc.ply.sprites[i].img->img,
				&c->sc.ply.sprites[i].img->bpp, &c->sc.ply.sprites[i].img->ll,
				&c->sc.ply.sprites[i].img->endian);
		i++;
	}
}
