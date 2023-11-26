/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:56:00 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:37:04 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* flood can be used to check if players world is souranded by walls
and can also check if all items are reachabel (not impl. yet) */
static bool	ft_flood(char **val, int x, int y, t_load *l)
{
	if (x < 0 || y < 0 || x >= l->xmap || y >= l->ymap || val[y][x] == ' ')
	{
		ft_printf("flood false: at [%i/%i]\n", y, x);
		return (false);
	}
	if (val[y][x] == '1' || val[y][x] == 'x')
		return (true);
	val[y][x] = 'x';
	if (!ft_flood(val, x + 1, y, l))
		return (false);
	if (!ft_flood(val, x - 1, y, l))
		return (false);
	if (!ft_flood(val, x, y + 1, l))
		return (false);
	if (!ft_flood(val, x, y - 1, l))
		return (false);
	return (true);
}

static int	check(t_load *load, char **val, int x, int y)
{
	if (x >= load->xmap || y >= load->ymap || val[y][x] == ' ')
		ft_printf("floor false: at [%i/%i]\n", y, x);
	return (x >= load->xmap || y >= load->ymap || val[y][x] == ' ');
}

static bool	ft_check_floor(char **val, t_load *load)
{
	int	j;
	int	i;

	j = -1;
	while (++j < load->ymap)
	{
		i = -1;
		while (++i < load->xmap)
		{
			if (val[j][i] != '1' && val[j][i] != ' ')
			{
				if (check(load, val, i + 1, j) || (i && check(load, val, i - 1,
							j)) || check(load, val, i, j + 1) || (j
						&& check(load, val, i, j - 1)))
					return (false);
			}
		}
	}
	return (true);
}

int	cub_checkmap(char **val, t_load *load)
{
	char	**temp;
	bool	valid;

	temp = cub_cparr(val);
	if (!temp)
		return (cub_error(E_MAL, 1, NULL, NULL));
	valid = ft_check_floor(temp, load);
	if (valid)
		valid = ft_flood(temp, *(load->xpl), *(load->ypl), load);
	cub_dfree(&temp);
	if (valid)
		return (0);
	return (cub_error(E_MW, 1, NULL, NULL));
}
