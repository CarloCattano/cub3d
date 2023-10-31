/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:03:58 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 16:53:49 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	fdf_temp(t_trans *temp, t_win *win)
{
	temp->x = -1;
	temp->y = win->ymax;
	temp->trgb = 0;
}

static void	fdf_maperror(int *fd, t_rpoint **data, char *error, char **p)
{
	ft_printf("%s\n", error);
	fdf_clearrpoint(data);
	*fd = -2;
	while (**p)
		(*p)++;
}

static void	fdf_make_entry(t_rpoint **data, t_trans *t, char **p, t_win *win)
{
	t->x++;
	fdf_setzwin(win, t);
	fdf_new_rpoint(data, t);
	if (data)
	{
		while (**p && ft_isspace(**p))
			(*p)++;
	}
}

void	fdf_split(int *fd, t_rpoint **data, t_win *win, char *line)
{
	t_trans	temp;

	fdf_temp(&temp, win);
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		temp.z = fdf_atoi_base(&line, 10, 0);
		if (*line == ',')
			temp.trgb = fdf_atoi_base(&line, 16, 3);
		if ((ft_isspace(*line) || !*line) && (!win->xmax || temp.x < win->xmax))
		{
			fdf_make_entry(data, &temp, &line, win);
			if (!data)
				fdf_maperror(fd, data, ERR_MMP, &line);
		}
		else
			fdf_maperror(fd, data, ERR_CMP, &line);
	}
	if (temp.x == -1 || temp.x < win->xmax)
		fdf_maperror(fd, data, ERR_EMP, &line);
	fdf_setxwin(win, &temp);
}
