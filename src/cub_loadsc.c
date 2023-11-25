/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loadsc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:21:23 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 16:53:16 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* free load struct */
static void	ft_lstdelone2(t_list *lst, void (*del)())
{
	if (lst)
	{
		del(&(lst->content));
		free(lst);
	}
}

static void	ft_lstclear2(t_list **lst, void (*del)())
{
	t_list	*temp;
	t_list	*curr;	

	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone2(curr, del);
		curr = temp;
	}
	*lst = NULL;
}

static void	ft_freeload(t_load *load)
{
	int	c;

	if (!load)
		return ;
	c = -1;
	while (++c < 4)
		gnl_free(&load->wall[c]);
	if (load->floor)
		free(load->floor);
	if (load->ceiling)
		free(load->ceiling);
	if (load->xpl)
		free(load->xpl);
	if (load->ypl)
		free(load->ypl);
	if (load->map)
		ft_lstclear2(&(load->map), gnl_free);
	if (load->extra)
		ft_lstclear2(&(load->extra), cub_freelextra);
}

int	cub_loadsc(int fd, t_sc *sc, t_cub *c)
{
	t_load	load;

	ft_bzero(c, sizeof(t_cub));
	if (cub_evalfile(fd, &load))
		return (ft_freeload(&load), 1);
	if (DEBUG)
		cub_pload(&load);
	ft_bzero(sc, sizeof(t_sc));
	if (cub_loadmap(&load, &(sc->map)))
		return (ft_freeload(&load), 1);
	cub_loadply(&load, &(sc->ply));
	cub_loadcfpl(sc, &load);
		c->mlx = mlx_init();
	if (cub_loadwalls(&load, sc, c->mlx))
		return (ft_freeload(&load), cub_freesc(sc, c->mlx), 1);
	if (EXTRAS)
	{
		if (cub_loadextra(&load, sc, c->mlx))
			return (ft_freeload(&load), cub_freesc(sc, c->mlx), 1);
	}
	return (ft_freeload(&load), 0);
}
