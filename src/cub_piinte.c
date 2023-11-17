/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_piinte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:28:15 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 22:16:00 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		cub_piinte(t_fp *fp)
{
	double x;
	double y;
	int index;
	char *tbuf;

	x = (double)fp->texX * fp->tex->xoff;
	y = (double)fp->texY * fp->tex->yoff; 
		
	index = (int)y * fp->tex->ll + (int) x * (fp->tex->bpp >> 3);
	tbuf = &(fp->tex->pix[index]);
	fp->texY += fp->step;
	return (*(int*)tbuf);
}
