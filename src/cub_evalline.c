/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	len(char *c1, char *c2)
{
	size_t a;
	size_t b;

	a = ft_strlen(c1);
	b = ft_strlen(c2);
	if (a > b)
		return (a);
	else
		return (b);

} 

int		ft_gettype(char *c)
{
		if (!c)
			return (0);
		if (ft_isdigit( *c))
			return (MAP);
		if (!ft_strncmp(c, "NO", len(c, "NO")))
			return (NO);
		if (!ft_strncmp(c, "SO", len(c, "SO")))
			return (SO);
		if (!ft_strncmp(c, "WE", len(c, "WE")))
			return (WE);
		if (!ft_strncmp(c, "EA", len(c, "EA")))
			return (EA);
		if (!ft_strncmp(c, "F", ft_strlen(c)))
			return (F);
		if (!ft_strncmp(c, "C", ft_strlen(c)))
			return (C);
		if (!ft_strncmp(c, "S", ft_strlen(c))|| !ft_strncmp(c, "W", ft_strlen(c)) || !ft_strncmp(c, "D", ft_strlen(c)) || !ft_strncmp(c, "E", ft_strlen(c)))
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
		return (cub_psprites(load, parts));
	if (type <= EA)
		return (cub_pwalls(load, parts, type));
	if (type <= C)
		return (cub_pfloor(load, line, type));
	return (cub_readmap (fd, load, ft_strdup(line)));
}			
