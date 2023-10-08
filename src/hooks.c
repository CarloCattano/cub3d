/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:54:41 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/08 19:54:42 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
	mouse pos 
*/

int	motion_hook(int x, int y, t_data *d)
{
	(void)d;
	(void)x;
	(void)y;
	return (1);
}

int	mouse_scaling_hook(int k, int x, int y, t_data *d)
{
	(void)d;
	if ((k == 1 || k == 2)
		&& (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == MOUSE_LEFT || k == MOUSE_RIGHT)
		{
		}
	}
	return (1);
}
