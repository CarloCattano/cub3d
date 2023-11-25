/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pwalls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:52:58 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 14:21:11 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_pwalls(t_load *load, char **parts, int type)
{
	int	fd;

	if (cub_countparts(parts) != 2)
		return (cub_error(E_SARG, 1, NULL, NULL));
	if (load->wall[type - 1])
		return (cub_error(E_SDT, 1, NULL, NULL));
	fd = open(parts[1], O_RDONLY);
	if (fd == -1)
		return (cub_error(E_SOTF, 2, NULL, NULL));
	load->wall[type - 1] = ft_strdup(parts[1]);
	if (!load->wall[type - 1])
		return (close(fd), cub_error(E_MAL, 1, NULL, NULL));
	close(fd);
	return (0);
}
