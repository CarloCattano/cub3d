/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <no@way.zip>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:21:36 by carlo             #+#    #+#             */
/*   Updated: 2023/11/26 14:16:04 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

clock_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	fps(t_cub *c)
{
	static int		fps = 0;
	static clock_t	last_time = 0;
	clock_t			current_time;

	current_time = get_time();
	if (current_time - last_time > 1000)
	{
		last_time = current_time;
		c->fps = fps;
		fps = 0;
	}
	else
		fps++;
}

void	add_frame(t_cub *c)
{
	c->frame++;
	if (c->frame >= 512)
		c->frame = 0;
	fps(c);
}
