/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:23:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:32 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	cub_point(double x, double y, int colour)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.colour = colour;
	return (point);
}


