/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:11:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:45:14 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**cub_cparr(char **parts)
{
	int		amount;
	char	**cp;
	int		i;

	amount = cub_countparts(parts);
	cp = (char **)malloc(sizeof(char *) * (amount + 1));
	if (!cp)
		return (NULL);
	i = -1;
	while (++i < amount)
	{
		cp[i] = ft_strdup(parts[i]);
		if (!cp[i])
			return (cub_dfree(&cp), NULL);
	}
	cp[i] = NULL;
	return (cp);
}
