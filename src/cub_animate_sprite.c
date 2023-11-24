/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_animate_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:13:23 by carlo             #+#    #+#             */
/*   Updated: 2023/11/24 19:46:05 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wp_sprites(t_cub *c)
{
	char	*paths[5];
	int		i;

	paths[0] = "./res/gun/gun3.xpm";
	paths[1] = "./res/gun/guna.xpm";
	paths[2] = "./res/gun/gunb.xpm";
	paths[3] = "./res/gun/gunc.xpm";
	paths[4] = "./res/gun/gund.xpm";
	c->sc.sprites = malloc(sizeof(t_sprites) * 5);
	i = 0;
	while (i < 5)
	{
		c->sc.sprites[i].path = paths[i];
		c->sc.sprites[i].img = malloc(sizeof(t_image));
		c->sc.sprites[i].img->img = mlx_xpm_file_to_image(c->mlx,
				c->sc.sprites[i].path, &c->sc.sprites[i].img->w,
				&c->sc.sprites[i].img->h);
		c->sc.sprites[i].img->pix = mlx_get_data_addr(c->sc.sprites[i].img->img,
				&c->sc.sprites[i].img->bpp, &c->sc.sprites[i].img->ll,
				&c->sc.sprites[i].img->endian);
		i++;
	}
}
