/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:18:13 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:23:58 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	cub_parser(char *input, t_sc *scene, t_cub *c)
{
	int		fd;
	size_t	len;

	if (!input)
		return (cub_error(ERROR_FILE, NULL, NULL));
	len = ft_strlen(input);
	if (len < 4 || ft_strncmp(input + len - 4, ".cub", 4))
		return (cub_error(ERROR_CUB, NULL, NULL));
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (perror("ERROR OPEN"), cub_error(ERROR_FILE_OPEN, NULL, NULL));
	return (cub_loadsc(fd, scene, c));
}

