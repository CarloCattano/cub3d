/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:25:57 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 19:16:07 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_zoom(t_spoint *data, t_win *win)
{
	data->z *= win->zdiv;
	data->x *= win->zoom;
	data->y *= win->zoom;
	data->z *= win->zoom;
}

void	fdf_setangle(t_win *win, float x, float y, float z)
{
	if (win->flags.cangle--)
	{
		win->angle.x = radian(x);
		win->angle.y = radian(y);
		win->angle.z = radian(z);
	}
	else
	{
		win->angle.x += radian(x);
		win->angle.y += radian(y);
		win->angle.z += radian(z);
	}
}
