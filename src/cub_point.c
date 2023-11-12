/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:23:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/12 15:08:47 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_point	cub_point(double x, double y, int colour)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.colour = colour;
	return (point);
}


