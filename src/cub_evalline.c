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

static size_t	ft_len(char *c1, char *c2)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(c1);
	b = ft_strlen(c2);
	if (a > b)
		return (a);
	else
		return (b);
}

static int	ft_extra(char *c)
{
	if (!ft_strncmp(c, "S", ft_strlen(c))|| !ft_strncmp(c, "W", ft_strlen(c)))
		return (1);
	if (!ft_strncmp(c, "D", ft_strlen(c)) || !ft_strncmp(c, "E", ft_strlen(c)))
		return (1);
	return (0);
}

static int	ft_gettype(char *c)
{
	if (!c)
		return (0);
	if (ft_isdigit( *c))
		return (MAP);
	if (!ft_strncmp(c, "NO", ft_len(c, "NO")))
		return (NO);
	if (!ft_strncmp(c, "SO", ft_len(c, "SO")))
		return (SO);
	if (!ft_strncmp(c, "WE", ft_len(c, "WE")))
		return (WE);
	if (!ft_strncmp(c, "EA", ft_len(c, "EA")))
		return (EA);
	if (!ft_strncmp(c, "F", ft_strlen(c)))
		return (F);
	if (!ft_strncmp(c, "C", ft_strlen(c)))
		return (C);
	if (ft_extra(c))
		return (S);
	return (0);
}

int	cub_evalline(int fd, t_load *load, char *line, char **parts)
{
	int type;

	type = ft_gettype(parts[0]);
	if (!type)
		return (ft_printf("%s\n", E_), 1);
	if (type == S)
	{
		if (EXTRAS) 
			return (cub_psprites(load, parts));
		return (cub_error(E_NE, 1, NULL, NULL));
	}
	if (type <= EA)
		return (cub_pwalls(load, parts, type));
	if (type <= C)
		return (cub_pfloor(load, line, type));
	return (cub_readmap (fd, load, ft_strdup(line)));
}
