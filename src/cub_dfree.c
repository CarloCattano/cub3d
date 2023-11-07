/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_dfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:20:20 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 14:21:04 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	cub_dfree(char ***tofree)
{
	int	i;

	i = 0;
	if (*tofree)
	{
		while ((*tofree)[i])
		{
			min_free(&((*tofree)[i]));
			i++;
		}
		free(*tofree);
		*tofree = NULL;
	}
}
