/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_animate_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:13:23 by carlo             #+#    #+#             */
/*   Updated: 2023/11/24 00:49:18 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* animate images logic works
 * but it needs allocated image frames
 * for the weapon anims	
 * 
 */

/* t_image	**init_all_frames(t_cub *d) */
/* { */
/* 	t_image **frames = malloc(4 * sizeof(t_image *)); */
/*     frames[0] = mlx_xpm_file_to_image(d->mlx, "./res/gun3.xpm", &d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h); */
/*     frames[1] = mlx_xpm_file_to_image(d->mlx, "./res/guna.xpm", &d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h); */
/*     frames[2] = mlx_xpm_file_to_image(d->mlx, "./res/gunb.xpm", &d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h); */
/*     frames[3] = mlx_xpm_file_to_image(d->mlx, "./res/gunc.xpm", &d->sc.ply.wp.img.w, &d->sc.ply.wp.img.h); */ 
/* 	return (); */
/* } */

/* void	cub_animate_sprite(t_cub *d) */
/* { */
/* 	static int		i = 0; */
/* 	static clock_t	start_t; */
/* 	clock_t			end_t; */

/* 	end_t = clock(); */
/* 	if (end_t - start_t > 100000) */
/* 	{ */
/*         i = (i + 1) % 4; */
/* 		start_t = end_t; */
/* 		d->sc.ply.wp.img = *(d->sc.ply.wp_imgs[i]); */
/* 	} */
/* } */

