/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:34:29 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 17:54:57 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H

# define FDF_H

/* LIB */
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h> 
# include "ft_printf.h"
# include <stdio.h>

/* DEFINE */

/*	WINDOW SETTINGS*/
# define WIDTHMAX 1024
# define HIGHTMAX 600 
# define WTEXT "FDF"

/*SETTINGS FDF */
# define ZOOM 1

/* ANGLE ISO*/		
# define ISX 30
# define ISY 330
# define ISZ 30

/* FLAG */
# define CENTER		1
# define ALL		0		
# define MOVE		1
# define COLOUR		0
# define ORTO 		1
# define POINTS		0
# define CANGLE		1	
# define SCALE		1

/* COLOUR */
# define LINE_COLOUR 0x00ff9632
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define YELLOW 0x00FFFF00
# define PINK 0x00e607f8
# define HBLUE 0x008ffcff

/* INFO TXT*/
# define IN_RMB "         START READING MAP"
# define OUT_RMB "        END READING MAP"
# define IN_SMP "         START STORING MAP"
# define OUT_SMP "        END STORING MAP"

/* FDF TXT */
# define TXT_EXP "        FDF: END -> ESC KEY			 "
# define TXT_CR "        FDF: END -> WINDOW X          "
# define TXT_BE	"#######################################"
# define TXT_MV "# MOVE:        ARROW KEYS             #"
# define TXT_ST "#--->         KEY SETTING         <---#"
# define TXT_RO "# ROTATION:  X->Q/W  Y->A/S  Z->Z/X   #"
# define TXT_ZO "# ZOOM:              G / H            #"
# define TXT_HI	"# HIGHT:             B / N            #"
# define TXT_CE	"# AUTOSCALE:           C              #"
# define TXT_RE "# RESET:               ~              #"
# define TXT_PE "# PERSPECTIVE:         1              #"
# define TXT_COL "# COLOUR:          SPACE              #"
# define TXT_EN	"#######################################"

/* ERROR TXT*/
# define ERR_OPEN "Error opening the file"
# define ERR_ARGS "Incorrect number of arguments, expected 1"
# define ERR_CLOSE "Error closing the file"
# define ERR_RMP "Error reading Map"
# define ERR_MMP "Error Memory allocation"
# define ERR_CMP "Error wrong content/format in Map "
# define ERR_EMP "Error empty Line or les argumments in Map"
# define ERR_ST "Error store Data"
# define ERR_FMP "MAP: Error Memory allocation"

/*MATH*/
# ifndef M_PI
#  define M_PI 3.141592654
# endif

/*	STRUCTS*/
/* MLX_IMG STRUCT */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/* HELPER_STRUCTS*/
/* FLAGS */
typedef struct s_eventsflags
{
	char	center;
	char	all;
	char	move;
	char	colour;
	char	orto;
	char	points;
	char	cangle;
	char	scale;
}	t_flags;

/* STRUCTS FOR OFFSET*/
/* x / y / z OFFSET 3D*/
typedef struct s_offset
{
	float	x;
	float	y;
	float	z;
}	t_off;

/* x / y / z ANGLE IN RADIANS */
typedef struct s_angle
{
	float	x;
	float	y;
	float	z;
}	t_angle;

/* x / y OFFSET 2D */
typedef struct s_move
{
	int		x;
	int		y;
	float	cx;
	float	cy;
}	t_move;	

typedef struct s_scale
{
	float	xmax;
	float	xmin;
	float	ymax;
	float	ymin;
}	t_scale;

/* POINTS / PIXEL */

/* COLOUR 3D*/
typedef struct s_colours
{
	int	trgb;
	int	t;
	int	r;
	int	g;
	int	b;
}	t_colour;

/* 3D POINT */
typedef struct s_storepoint
{
	float		x;
	float		y;
	float		z;
	t_colour	colour;
}	t_spoint;

/* COLOUR 2D */
typedef struct s_colgrad
{
	int		trgb;
	char	first;
	int		t;
	int		tof;
	int		r;
	int		rof;
	int		g;
	int		gof;
	int		b;
	int		bof;
}	t_colgrad;

/* 2D POINT */
typedef struct s_2Dpoint
{
	float		x;
	float		y;
	float		z;
	t_colgrad	colour;
}	t_ppoint;

/* LINE_STRUCT */
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
	t_colgrad	colour;
	int			w;
	int			h;
}	t_line;	

/* MAP POINT */
typedef struct s_readpoint
{
	int					x;
	int					y;
	int					z;
	int					trgb;
	struct s_readpoint	*next;
}	t_rpoint;

/* MAP 3D TRANSFAIRPOINT */
typedef struct s_transfair
{
	int	x;
	int	y;
	int	z;
	int	trgb;
}	t_trans;

/*IMG_RENDER_STRUCT*/
typedef struct s_win
{
	int			pp;
	int			ww;
	int			wh;
	float		width;
	float		hight;
	int			zmax;
	int			zmin;
	int			xmax;
	int			ymax;
	t_off		axcoff;
	float		zoom;
	float		rscale;
	float		zdiv;
	t_move		move;
	t_angle		angle;
	t_colour	colour;
	t_flags		flags;
	t_scale		scale;
	int			icol;
}	t_win;

/* MAIN_ STRUCT */
typedef struct s_fdf
{
	void				*mlx;
	void				*mlx_win;
	t_img				img;
	t_win				win;
	t_spoint			*store;
}						t_fdf;

/* FUNCTIONS */
/* MAIN */
void		fdf_load_map(char *map, t_fdf *fdf);
void		fdf_start(t_fdf *fdf);
void		fdf_setup(t_fdf *fdf);

/* WINDOW SETTING*/
void		fdf_init_window(t_win *win);
void		fdf_setwin(t_win *win);
void		fdf_setflags(t_win *win);
void		fdf_inscale(t_scale *scale);

/* DRAW */
void		fdf_draw(t_fdf *fdf);
void		fdf_img(t_fdf *fdf, t_img *img);
t_ppoint	fdf_render(t_spoint point, t_win *win);
void		fdf_draw_points(t_ppoint *map, t_img *img, t_win *win);
void		fdf_draw_lines(t_ppoint *map, t_img *img, t_win *win);

/*LINE*/
void		line(t_ppoint a, t_ppoint b, t_img *datai, t_win *win);

/* HOCK */
void		fdf_hock_init(t_fdf *fdf);
int			keypress(int keycode, t_fdf *fdf);
int			fdf_close( t_fdf *fdf);
void		fdf_keycolour(t_fdf *fdf);
void		fdf_keymove(int keycode, t_fdf *fdf);
void		fdf_keyrest(t_fdf *fdf);
void		fdf_keyzdiv(int keycode, t_fdf *fdf);
void		fdf_keyzoom(int keycode, t_fdf *fdf);
void		fdf_keyangle(int keycode, t_fdf *fdf);
void		fdf_keyflags(int keycode, t_fdf *fdf);

/*3D POINT*/
t_spoint	fdf_spoint(t_rpoint *pars, t_win *win);

/*3D POINT MANUPILATION */
void		fdf_setangle(t_win *win, float x, float y, float z);
void		fdf_perangle(t_win *win);
void		fdf_zoom(t_spoint *data, t_win *win);
void		fdf_rotation(t_spoint *data, t_angle *angle);

/*3D ROTATION*/
void		rotationx(t_spoint *data, t_angle *angle);
void		rotationy(t_spoint *data, t_angle *angle);
void		rotationz(t_spoint *data, t_angle *angle);

/* 2D scale and center*/
void		fdf_center(t_ppoint *nwpoint, t_win *win, int scale);

/* MAPPARSE */
t_spoint	*fdf_map_rss(int fd, t_win *win);
t_rpoint	*fdf_map_rs(int fd, t_win *win);
void		fdf_split(int *fd, t_rpoint **data, t_win *win, char *line);
t_spoint	*fdf_store(t_rpoint **lldata, t_win *win);

/*RPOINT*/
void		fdf_new_rpoint(t_rpoint **lldata, t_trans *temp);
t_rpoint	*fdf_new_node(int x, int y, int z, int colour);
t_rpoint	*fdf_lstnode(t_rpoint *lst);
void		fdf_add_back(t_rpoint **lst, t_rpoint *new);
void		fdf_clearrpoint(t_rpoint **lst);
void		fdf_add_front(t_rpoint **lst, t_rpoint *new);
t_rpoint	*fdf_pop(t_rpoint **data);

/* HELPERS */
int			fdf_atoi_base(char **nptr, int base, int off);
void		fdf_setxwin(t_win *win, t_trans *temp);
void		fdf_setzwin(t_win *win, t_trans *temp);
void		fdf_swap(t_ppoint *a, t_ppoint *b);

/*EXIT*/
void		fdf_end(t_fdf *fdf, char error, char *text, char extra);
void		fdf_destroy_win(t_fdf *fdf);
void		fdf_destroy_img(t_fdf *fdf);
void		fdf_exit(char *text);
void		fdf_exit_error(char *error, int extra);

/* COLOURS*/
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			get_r(int trgb);
int			fdf_set_col(t_colgrad *col, int t);
int			set_div(int dx, int dy);
t_colgrad	fdf_in_col(t_ppoint *a, t_ppoint *b, int dx, int dy);
t_colour	fdf_storecolour(int trgb);

/* MATH */
float		degree(float radians);
float		radian(float dagree);

/* Debug*/
/*void	printspoint(t_spoint point);
void	printppoint(t_ppoint point);
void	spointprint(t_spoint *store, t_win *win);
void	ppointprint(t_ppoint *map, t_win *win);
*/
/* LATER TO LIBFT */
int			ft_islower(int a);
int			ft_isupper(int a);
int			ft_isspace(int a);
int			ft_isdigit(int a);
#endif
