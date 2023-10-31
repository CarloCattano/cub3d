/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:54:40 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/02 09:32:38 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	rotationx(t_spoint *data, t_angle *angle)
{
	t_spoint	temp;

	temp = *data;
	data->y = cos(angle->x) * temp.y - sin(angle->x) * temp.z;
	data->z = sin(angle->x) * temp.y + cos(angle->x) * temp.z;
}

void	rotationy(t_spoint *data, t_angle *angle)
{
	t_spoint	temp;

	temp = *data;
	data->x = cos(angle->y) * temp.x + sin(angle->y) * temp.z;
	data->z = -sin(angle->y) * temp.x + cos(angle->y) * temp.z;
}

void	rotationz(t_spoint *data, t_angle *angle)
{
	t_spoint	temp;

	temp = *data;
	data->x = cos(angle->z) * temp.x - sin(angle->z) * temp.y;
	data->y = sin(angle->z) * temp.x + cos(angle->z) * temp.y;
}

void	fdf_rotation(t_spoint *data, t_angle *angle)
{
	rotationx(data, angle);
	rotationy(data, angle);
	rotationz(data, angle);
}
