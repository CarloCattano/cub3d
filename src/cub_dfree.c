/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_dfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:20:20 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 11:58:08 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_dfree(char ***tofree)
{
	int	i;

	i = 0;
	if (*tofree)
	{
		while ((*tofree)[i])
		{
			gnl_free(&((*tofree)[i]));
			i++;
		}
		free(*tofree);
		*tofree = NULL;
	}
}
