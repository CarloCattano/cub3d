/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:30:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/10 17:49:38 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



static int ft_init_map(t_map *map)
{
	int c;

	map->val = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->val)
		return (1);
	c = -1;
	while (++c < map->height)
	{
		(map->val)[c] = (char *)malloc(sizeof(char) * (map->width + 1)); 			
		if (!(map->val)[c])
			return (cub_dfree(&(map->val)), 1);
	}
	map->val[map->height] = NULL;
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
		len = (int)ft_strlen(lmap->content);
		while (++x < map->width)
		{
			if	(x < len)
			{
				if ((((char *)(lmap->content))[x]) != dir)
					(map->val)[y][x] = ((char *)(lmap->content))[x];
				else
					(map->val)[y][x] = '0';
			}
			else 
				(map->val)[y][x] = ' ';
		}
		lmap = lmap->next;	
	}
	return (0);
}

bool ft_flood(char **val, int x, int y, t_load *load)
{
	
	if (x < 0 || y < 0 || x >= load->xmap || y >= load->ymap || val[y][x] == ' ')
	{
		printf("wrong at [%i][%i]\n", y  + 1, x + 1);
		return false;
	} 
	if ( val[y][x] == '1' || val[y][x] == 'x') 
		return true;
	val[y][x] = 'x';
	if (!ft_flood(val, x + 1 ,y , load))
		return (false);	
	if (!ft_flood(val, x - 1,y , load))
		return (false);	
	if (!ft_flood(val, x ,y + 1, load))
		return (false);	
	if (!ft_flood(val, x ,y -1, load))
		return (false);
	return (true);
}


bool ft_checkmap(char **val, t_load *load)
{
	char **temp;
	bool	valid;	
	
	temp = cub_cparr(val);
	if (!temp)
		return (cub_error(E_MAL, NULL, NULL));
	valid = ft_flood(temp, *(load->xpl), *(load->ypl), load); 	
	cub_dfree(&temp);
	return (valid);
}



int cub_loadmap(t_load *load, t_map *map)
{
	map->height =  load->ymap;
	map->width = load->xmap;
	if (ft_init_map(map))
		return (cub_error(E_MAL, NULL, NULL));
	if (ft_cpmap(map, load->map, load->dir) || !ft_checkmap(map->val, load))
		return (cub_error(M_W, NULL, NULL));
	return (0);
}
