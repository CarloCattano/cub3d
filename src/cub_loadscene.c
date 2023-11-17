/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadsc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:21:23 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:14:27 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


/*
static void ft_delmmap()
{



}*/
// void mprint(void *value)
// {
//         printf("%s\n", (char *)value);
// }

// static void eprint(void *value)
// {
// 	printf("%s ", ((t_lextra *)value)->key);
// 	printf("%s ", ((t_lextra *)value)->path);
// 	while (*((t_lextra *)value)->value)
// 		printf("%s ", *((t_lextra *)value)->value++);
// 	printf("\n");	
// }

// static void ft_pload(t_load *l)
// {
	
// 	// printf("\n");	
// 	// printf("W1:  %s\n", l->wall[0]);			
// 	// printf("W2:  %s\n", l->wall[1]);			
// 	// printf("W3:  %s\n", l->wall[2]);
// 	// printf("W4:  %s\n", l->wall[3]);
// 	// printf("F:  %i\n", *(l->floor));
// 	// printf("C:  %i\n", *(l->ceiling));
// 	// printf("\n");	
// 	ft_lstiter(l->map, mprint);
// 	// printf("height: %i, width: %i\n", l->ymap, l->xmap);
// 	// printf("ply [ DIR: %c / x: %i / y: %i]\n", l->dir, *l->xpl, *l->ypl);
	
// 	// printf("\n");	
// 	ft_lstiter(l->extra, eprint);
				
// }




static void ft_freeload(t_load *load)
{
	int c;

	if (!load)
		return;
	c = -1;
	while (++c < 3)
		gnl_free(&load->wall[c]);
	if (load->floor)
		free(load->floor);
	if (load->ceiling)
		free(load->ceiling);
/*	
	if (load->map)
		ft_lstclear(&(load->map), gnl_free);
	if (load->extra)
		ft_lstclear(&(load->extra),  cub_freelextra);	
*/
}


int	cub_loadsc(int fd, t_sc *sc, t_cub *c)
{
	t_load	load;
	
	if (cub_evalfile(fd, &load))
		return (ft_freeload(&load), 1);	
	//if (DEBUG)
	//ft_pload(&load);	   	
	ft_bzero(sc, sizeof(t_sc));
	if (cub_loadmap(&load, &(sc->map)))
		return (ft_freeload(&load), 1);   	
	if (cub_loadply(&load, &(sc->ply)))
		return (ft_freeload(&load), /*ft_freesc(sc),*/ 1);
	sc->c_floor = *load.floor;
	sc->c_ceiling = *load.ceiling;
	sc->plane_x =  - sc->ply.diry;
	sc->plane_y =  sc->ply.dirX;
	ft_bzero(c, sizeof(t_cub));
	c->mlx = mlx_init();
	if (cub_loadwalls(&load, sc, c->mlx))
		return (ft_freeload(&load), /*ft_freesc(sc),*/ 1);   	
	/*if (cub_loadextra(&load), sc, c->mlx)
		return (ft_freeload(&load), 1);
	*/
	return (ft_freeload(&load), 0);

}
