/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:13:02 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 00:27:02 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

/* structs */
typedef enum e_type			t_type;
typedef struct s_image		t_image;
typedef struct s_sc			t_sc;
typedef struct s_map		t_map;
typedef struct s_sprites	t_sprites;
typedef struct s_lextra		t_lextra;
typedef struct s_extra		t_extra;
typedef struct s_map		t_map;
typedef struct s_load		t_load;
typedef struct s_cub		t_cub;
typedef struct s_fp			t_fp;	

enum e_type
{
	NOT = 0,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	S,
	MAP	
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17,
	ON_WIN_LEAVE = 8,
	ON_WIN_ENTER = 7
};

typedef struct s_ctrl_states
{
	int		up_down;
	int		left_right;
	int		turn;
}			t_ctrl_states;

struct s_image
{
	void		*img;
	char		*pix;
	int			ll;
	int			bpp;
	int			endian;
	int			w;
	int			h;
	int			wxoff;
	int			wyoff;
	double		xoff;
	double		yoff;
};

typedef struct s_wp
{
	t_image		img;
	char		*path;
}				t_wp;

typedef struct s_ply
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			movespeed;
	double			rotSpeed;
	int				rot;
	int				lastX;
	t_wp			wp;
	t_ctrl_states	ctrl;
	int				wp_s;
	int				shooting;
	int				walking;
	t_sprites		*sprites;
	t_image			**wp_imgs;
}					t_ply;

struct s_map
{
	int		height;
	int		width;
	char	**val;
};

struct s_sc
{
	bool		setting[3];
	int			c_floor;
	int			c_ceiling;
	double		plane_x;
	double		plane_y;
	t_image		*floor;
	t_image		*ceiling;
	t_image		wall[4];
	t_map		map;
	t_ply		ply;
	t_image		*wp;
	t_sprites	*sprites;
	t_extra		*extra;
};

struct s_sprites
{
	int				x;
	int				y;
	double			z;
	t_image			*img;
	char			*path;
	double			dist;
	int				hdiv;
	int				vdiv;
	t_sprites		*next;
};

struct	s_extra
{
	char		*key;
	t_image		extra;
	t_extra		*next;
};	

struct s_lextra
{
	char	*key;
	char	*path;
	char	**value;
};

struct	s_load
{
	char	*wall[4];
	int		*floor;
	int		*ceiling;
	int		*xpl;
	int		*ypl;
	char	dir;
	int		xmap;
	int		ymap;
	t_list	*map;
	t_list	*extra;
};

/* draw lines */
typedef struct s_2Dpoint
{
	float		x;
	float		y;
	int			colour;
}	t_point;

typedef struct s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
	int			ax;
	int			ay;
	int			bx;
	int			by;
	int			colour;
	int			w;
	int			h;
}	t_line;	

struct	s_cub
{
	void			*mlx;
	void			*win;
	t_sc			sc;
	t_image			scr;
	t_image			mini;
	float			fps;
	int				bonus;
	unsigned int	frame;
};

struct s_fp
{
	double	wx;
	int		ds;
	int		de;
	t_image	*tex;
	int		texx;
	double	step;
	double	texy;
	double	scalar;	
};

typedef struct s_ray
{/*
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sideDisty;
	double		perpWallDist;
	int			lineHeight;
	int			side;
	double		hitX;
	double		hitY;
	double		camerax;
	*/
	double      rdx;
    double      rdy;
    double      ddx;
    double      ddy;
    int         stx;
    int         sty;
    double      sdx;
    double      sdy;
    double      pwd;
    int         lh;
    int         s;
    double      hx;
    double      hy;
    double      cx;
}				t_ray;

#endif
