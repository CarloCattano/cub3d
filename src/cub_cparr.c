/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:11:08 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **cub_cparr(char **parts)
{
	int amount;
	char **cp;
	int i;
	
	amount = cub_countparts(parts);
	cp = malloc(sizeof(char *) * (amount + 1)); 
	if (!cp)
		return (NULL);
	i = -1;
	while (parts[++i])
	{
		cp[i] = ft_strdup(parts[i]);	
		if (!cp[i])
			return (cub_dfree(&cp), NULL);
	}
	cp[i] = NULL;	
	return (cp);
}
