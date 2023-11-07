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
static void ft_freeload(t_load *load)
{


}


int	cub_loadscene(int fd, t_scene *scene)
{
	t_load	load;
	
	if (cub_evalfile(fd, &load))
		return (ft_freeload(&load), 1);   	
	if (cub_loadmap(&load), scene)
		return (ft_freeload(&load), 1);   	
	if (cub_loadtexture(&load), scene)
		return (ft_freeload(&load), 1);   	
	if (cub_loadsprites(&load), scene)
		return (ft_freeload(&load), 1);   	
	if (cub_loadextra(&load), scene)
		return (ft_freeload(&load), 1);   	
	return (ft_freeload(&load), 0); 

}
