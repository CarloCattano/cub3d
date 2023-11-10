/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:30:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/10 12:21:21 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



static int ft_init_map(t_map *map)
{
	int c;

	map->val = (char **)malloc(sizeof(char *) * (map->height));
	if (!map->val)
		return (1);
	c = -1;
	ft_bzero(map->val, sizeof(char *));
	while (++c < map->height)
	{
		(map->val)[c] = (char *)malloc(sizeof(char) * (map->width)); 			
		if (!(map->val)[c])
			return (cub_dfree(&map), 1);
	}		
	return (0);
}

int	ft_cpmap(t_map *map, t_list *lmap, char dir)
{
	int y;
	int x;
	int len;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		len = (int)ft_strlen(lmap->value);
		while (++x < map->width)
		{
			if	(x < len)
			{
				if ((lmap->value)[x] != dir)
					(map->val)[y][x] = (lmap->value)[x]
				else
					(map->val)[y][x] = '0'
			}
			else 
				(map->val)[y][x] = ' ';
		}
		lmap = lmap->next;	
	}
	return (0);
}

int	ft_checkmap(char **val)
{
	int x;
	int y;

	


}



int cub_loadmap(t_load *load, t_map *map)
{
	map->height =  load->ymap;
	map->width = load->xmap;
	if (ft_init_map(map))
		return (cub_error(E_MAL, NULL, NULL));
	if (ft_cpmap(map, load->map, load->dir) && ft_checkmap(map->val))
		return (cub_error(M_W, NULL. NULL);
	return (0);
}
	 	



}
