/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freelextra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:58:20 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:54:02 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_freelextra(t_lextra **node)
{
	if (*node)
	{
		if ((*node)->key)
			free((*node)->key);
		if ((*node)->path)
			free((*node)->path);
		if ((*node)->value)
			cub_dfree(&((*node)->value));
		free (*node);
	}
	*node = NULL;
}
