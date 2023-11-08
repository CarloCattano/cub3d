/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 17:45:23 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_gettype(char *c)
{
		if (!c)
			return (0);
		if (ft_isdigit( *c)
			return (MAP);
		if (!ft_strcmp(c, "NO"))
			return (NO);
		if (!ft_strcmp(c, "SO"))
			return (SO);
		if (!ft_strcmp(c, "WE"))
			return (WE);
		if (!ft_strcmp(c, "EA"))
			return (EA);
		if (!ft_strcmp(c, "F"))
			return (F);
		if (!ft_strcmp(c, "C"))
			return (C);
		if (!ft_strcmp(c, "S")|| !ft_strcmp(c, "W") || !ft_strcmp(c, "D") || \
			!ft_strcmp(c, "E"))
			return (S);
		return (0);
}

int		cub_evalline(int fd, t_load *load,  char *line, char **parts)
{
	int type;
	
	type = ft_gettype(parts[0]);
	if (!type)
		return (1);
	if (type == S)
		return (cub_psprite(load, parts));
	if (type <= EA)
		return (cub_pwalls(load, parts, type);
	if (type <= C)
		return (cub_pfloor(load, line, type);
	return (cub_readmap (fd, load, ft_strdup(line)));
}			
