/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:55:03 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:12:14 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_setxwin(t_win *win, t_trans *temp)
{
	if (!win->xmax)
		win->xmax = temp->x;
}

void	fdf_setzwin(t_win *win, t_trans *temp)
{
	if (temp->z < win->zmin)
		win->zmin = temp->z;
	if (temp->z > win->zmax)
		win->zmax = temp->z;
}

/*   */
int	fdf_atoi_base(char **p, int base, int off)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (**p && off--)
		(*p)++;
	while (ft_isspace(**p))
		(*p)++;
	if (**p == '-')
		sign = -1;
	if (**p == '+' || **p == '-')
		(*p)++;
	while ((base > 10 && ((ft_isupper(**p) && **p - 'A' + 10 < base)
				|| (ft_islower(**p) && **p - 'a' + 10 < base)))
		|| ft_isdigit(**p))
	{
		if (ft_isdigit(**p))
			num = num * base + *(*p)++ - '0';
		if (base > 10 && (ft_isupper(**p) && **p - 'A' + 10 < base))
			num = num * base + *(*p)++ - 'A' + 10;
		if (base > 10 && (ft_islower(**p) && **p - 'a' + 10 < base))
			num = num * base + *(*p)++ - 'a' + 10;
	}
	return (num * sign);
}
