/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadscene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:21:23 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 12:09:33 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


/*
static vois ft_delmmap()
{



}*/
void mprint(void *value)
{
        printf("%s\n", (char *)value);
}

void eprint(void *value)
{
	printf("%s\n", (t_lextra *)value->key);
	printf("%s\n", (t_lextra *)value->path);
}

ft_pload(t_load *l)
{
	printf("W1:  %s\n", l->wall[0]);			
	printf("W2:  %s\n", l->wall[1]);			
	printf("W3:  %s\n", l->wall[2]);
	printf("F:  %i\n", *(l->floor));
	printf("C:  %i\n", *(l->ceiling));
	ft_lstiter(l->map, mprint);
	ft_lstiter(l->exxtra, eprint);
				
}




static void ft_freeload(t_load *load)
{
	int c;

	if (!load)
		return;
	c = -1;
	while (++c < 3)
		gnl_free(load->wall[i]);
	if (load->floor)
		free(load->floor);
	if (load->ceiling)
		free(load->ceiling);
	if (load->map)
		ft_lstclear(&(load->map), gnl_free);
	if (load->extra)
		ft_lstclear(&(load->extra),  cub_freelextra);	
}


int	cub_loadscene(int fd, t_scene *scene)
{
	t_load	load;
	
	if (cub_evalfile(fd, &load))
		return (ft_freeload(&load), 1);
	/*   	
	if (cub_loadmap(&load), scene)
		return (ft_freeload(&load), 1);   	
	if (cub_loadwalls(&load), scene)
		return (ft_freeload(&load), 1);   	
	if (cub_loadextra(&load), scene)
		return (ft_freeload(&load), 1);
	*/
	ft_pload(&load);	   	
	return (ft_freeload(&load), 0);

}