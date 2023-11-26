/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:29 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 14:19:12 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* print for debug */
void	mprint(void *value)
{
	ft_printf("[%s]\n", (char *)value);
}

static void	eprint(void *value)
{
	ft_printf("%s ", ((t_lextra *)value)->key);
	ft_printf("%s ", ((t_lextra *)value)->path);
	while (*((t_lextra *)value)->value)
		ft_printf("%s ", *((t_lextra *)value)->value++);
	ft_printf("\n");
}

void	cub_pload(t_load *l)
{
	ft_printf("\n");
	ft_printf("W1:  %s\n", l->wall[0]);
	ft_printf("W2:  %s\n", l->wall[1]);
	ft_printf("W3:  %s\n", l->wall[2]);
	ft_printf("W4:  %s\n", l->wall[3]);
	ft_printf("F:  %i\n", *(l->floor));
	ft_printf("C:  %i\n", *(l->ceiling));
	ft_printf("\n");
	ft_lstiter(l->map, mprint);
	ft_printf("height: %i, width: %i\n", l->ymap, l->xmap);
	ft_printf("ply [ DIR: %c / x: %i / y: %i]\n", l->dir, *l->xpl, *l->ypl);
	ft_printf("\n");
	ft_lstiter(l->extra, eprint);
}
