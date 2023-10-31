/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_endfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:20:17 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 16:57:28 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit_error(char *error, int extra)
{
	ft_printf("ERROR:  %s\n", error);
	if (extra)
		perror("PError: ");
	exit(EXIT_FAILURE);
}

void	fdf_exit(char *text)
{
	ft_printf("%s\n", text);
	exit(EXIT_SUCCESS);
}

void	fdf_destroy_img(t_fdf *fdf)
{
	if (fdf->img.img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		fdf->img.img = NULL;
	}
}

void	fdf_destroy_win(t_fdf *fdf)
{	
	if (fdf->mlx_win)
	{
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		fdf->mlx_win = NULL;
	}
}

void	fdf_end(t_fdf *fdf, char error, char *text, char extra)
{
	fdf_destroy_img(fdf);
	fdf_destroy_win(fdf);
	free(fdf->store);
	fdf->store = NULL;
	mlx_loop_end(fdf->mlx);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	if (error)
		fdf_exit_error(text, extra);
	else
		fdf_exit(text);
}	
