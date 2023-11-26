/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_piinte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:28:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:36:24 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Cube texture mapping
 * Ensure x and y are within the texture bounds
 * Handle negative x and y
 * Return the color of the pixel at (x, y)
*/

int	cub_piinte(t_fp *fp)
{
	double	x;
	double	y;
	int		index;
	char	*tbuf;

	x = fp->texx * fp->tex->xoff;
	y = fp->texy * fp->tex->yoff;
	x = fmod(x, fp->tex->w);
	y = fmod(y, fp->tex->h);
	if (x < 0)
		x += fp->tex->w;
	if (y < 0)
		y += fp->tex->h;
	index = ((int)y) * fp->tex->ll + x * (fp->tex->bpp >> 3);
	tbuf = &(fp->tex->pix[index]);
	fp->texy += fp->step;
	return (*(int *)tbuf);
}
