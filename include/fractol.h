/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:40:18 by carlo             #+#    #+#             */
/*   Updated: 2023/10/03 11:11:03 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include "ft_printf.h"
# include <math.h>
# include "key_codes.h"
# define WIDTH 680
# define HEIGHT 680

enum {
	ON_KEYDOWN = 2,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17
};

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct s_image
{
	void			*mlx;
	void			*win;
	int				*image;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_image;

typedef struct s_3d
{
	t_image			img;
	int				color;
	int				menu;
}					t_3d;

void				init_img(t_3d *d);
void				settings(t_3d *d);

/*
	HOOKS
*/

int					motion_hook(int x, int y, t_3d *d);
int					key_hook(int keycode, t_3d *d);
int					mouse_scaling_hook(int button, int x, int y, t_3d *d);

int					ft_clip(int n, int min, int max);
int					terminate(t_3d *d);

#endif 
