/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:12:20 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:17:42 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

float	degree(float radians)

{
	return (radians * (180 / M_PI));
}

float	radian(float dagree)
{
	return ((dagree * M_PI) / 180);
}
