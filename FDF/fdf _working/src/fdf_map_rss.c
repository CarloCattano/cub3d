/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_rss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:03:25 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 16:53:16 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/* to remove -> ckeck for debugging */
/*static void	print_rpoint(t_rpoint	*lldata)
{
	while (lldata)
	{
		printf("Punkt:{[x: %i /y: %i /z: %i] colour: %x} \n", 
		lldata->x, lldata->y, lldata->z, lldata->trgb);
		lldata = lldata->next;
	}
}	
*/

/* Read map and make when storing decision */
t_spoint	*fdf_map_rss(int fd, t_win *win)
{
	t_spoint	*store;
	t_rpoint	*data;

	data = fdf_map_rs(fd, win);
	if (!data)
	{
		close(fd);
		fdf_exit_error(ERR_RMP, 1);
	}
	ft_printf("%s\n%s\n", OUT_RMB, IN_SMP);
	store = fdf_store(&data, win);
	fdf_clearrpoint(&data);
	if (!store)
		fdf_exit_error(ERR_ST, 1);
	ft_printf("%s\n", OUT_SMP);
	return (store);
}
