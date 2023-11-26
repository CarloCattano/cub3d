/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:30:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:43:13 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* do ineed the NUll at the end of the height and width*/
static int	ft_init_map(t_map *map)
{
	int	c;

	map->val = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->val)
		return (1);
	ft_bzero(map->val, (sizeof(char *) * (map->height + 1)));
	c = -1;
	while (++c < map->height)
	{
		(map->val)[c] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!(map->val)[c])
			return (cub_dfree(&(map->val)), 1);
	}
	return (0);
}

static void	ft_cpmap(t_map *map, t_list *lmap, char dir)
{
	int	y;
	int	x;
	int	len;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		len = (int)ft_strlen(lmap->content);
		while (++x < map->width)
		{
			if (x < len)
			{
				if ((((char *)(lmap->content))[x]) != dir)
					(map->val)[y][x] = ((char *)(lmap->content))[x];
				else
					(map->val)[y][x] = '0';
			}
			else
				(map->val)[y][x] = ' ';
		}
		(map->val)[y][x] = 0;
		lmap = lmap->next;
	}
}

int	cub_loadmap(t_load *load, t_map *map)
{
	map->height = load->ymap;
	map->width = load->xmap;
	if (ft_init_map(map))
		return (cub_error(E_MAL, 1, NULL, NULL));
	ft_cpmap(map, load->map, load->dir);
	if (cub_checkmap(map->val, load))
		return (cub_dfree(&(map->val)), 1);
	return (0);
}
