/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:18:13 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:05:21 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_parser(char *input, t_sc *scene, t_cub *c)
{
	int		fd;
	size_t	len;

	if (!input)
		return (cub_error(E_FILE, 1, NULL, NULL));
	len = ft_strlen(input);
	if (len < 4 || ft_strncmp(input + len - 4, ".cub", 4))
		return (cub_error(E_CUB, 1, NULL, NULL));
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (cub_error(E_FO, 2, NULL, NULL));
	return (cub_loadsc(fd, scene, c));
}
