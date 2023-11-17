/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/17 18:47:37 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/* inc */
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>	
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdbool.h>
# include "mlx.h"
# include "key_codes.h"
# include "constants.h"
/* constants */

/* MAP */
# define DIRECT "NSEW"
# define INMAP	" 10D"

/* WINDOWS  */
# define WIDTH 800
# define HEIGHT 600
# define MWIDTH 200
# define MHEIGHT 200

/* TEXTURE */
# define TX 64	
# define TY 64

/* PLAYER */
# define FOV 0.66

/* COLOURS MINIMAP*/

# define W1 0xffffd39b
# define W2 0xff8b7355
# define F1 0xff545454
# define F2 0xff8deeee
# define PL 0xff0000ff
# define RY 0xffff0000

/* MSG */
# define ERROR_ARG "CUBE3D NEEDS ONLY ONE ARG"
# define ERROR_PARS "PARSING FAILD"
# define ERROR_FILE "CUB FILE CORRUPTED" 
# define ERROR_CUB "FILE NEED .CUB EXTENSION"
# define ERROR_FILE_OPEN "OPEN CUB FILE FAIL"
# define E_FW " FILE IS NOT RIGHT CINFIGUERD"
# define E_MAL	"MALLOC_FAIL"
/* MSG CUB FILE */
# define SAMEARG " .CUB HAVE DUPLICATE TYPES "
# define SCENEARG " .CUB TYPE HAS NOT THE RIGHT NUMBER OF ARG"	
# define SCENECOL " .CUB HAS DUPLICATE COLOUR "
# define SCENEWCOL " .CUB WRONG COLOUR IMNPUT "	
# define SOPEN " .CUB OPEN TEXTURE FAIL"
# define E_M " MAP IS NOT CORRECT"	
# define E_T " NOT ALL NECESSARY TYPES ARE DECLAIRED BEFOR MAP"
# define M_P " MULTIPLE PLAYER"
# define M_W "MAP NOT CLOESD BY WALLS"
#define MAIN "MAIN FAILOR"
/* structs */

typedef enum e_type t_type;
typedef struct s_image	t_image;
typedef struct s_scene t_scene;
typedef struct s_map t_map;
typedef	struct s_sprites t_sprites;
typedef struct s_lextra	t_lextra;
typedef struct s_extra	t_extra;
typedef struct s_map	t_map;
typedef struct s_load	t_load;
typedef struct s_cub	t_cub;
typedef struct s_fp		t_fp;	

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
	int			line_length;
	int			bpp;
	int			endian;
	int 		w;
	int 		h;
	int			wxoff;
	int			wyoff;
	double		xoff;
	double		yoff;
};

typedef struct	s_weapon
{
	t_image		img;
	char		*path;
}				t_weapon;

typedef struct s_player
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			moveSpeed;
	double			rotSpeed;
	int				lastX;
	t_weapon		weapon;
	t_ctrl_states	ctrl;
}					t_player;

struct s_map
{
	int		height;
	int		width;
	char	**val;
};

struct s_scene
{
	bool		setting[3];
	int			c_floor;
	int			c_ceiling;
	double		planeX;
	double		planeY;
	t_image		*floor;
	t_image		*ceiling;
	t_image		wall[4];
	t_map		map;
	t_player	player;
	t_image		*weapon;
	t_sprites 	*sprites;
	t_extra		*extra;
};

struct s_sprites
{
	int				x;
	int				y;
	t_image				sprites;
	double				z;
	double				dist;
	int					hdiv;
	int					vdiv;
	t_sprites			*next;
};

struct	s_extra
{
	char	*key;
	t_image	extra;
	t_extra *next;	
};	

struct s_lextra
{
	char *key;
	char *path;		
	char **value;
};

struct	s_load
{
	char *wall[4];
	int *floor;
	int *ceiling;
	int *xpl;
	int *ypl;
	char dir;
	int xmap;
	int ymap;
	t_list *map;
	t_list *extra;
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

/* test raycast minimap etc */

struct	s_cub
{
	void				*mlx;
	void				*win;
	int					win_h;
	int					win_w;
	t_scene				scene;
	t_image				screen;
	t_image				mini;
};

struct s_fp
{
	/* image */
	t_image *tex;
	/* x */
	double	texX;
	/* y*/ 
	double	step;
	double  texY;  	
};		

/* rays */
typedef struct s_ray
{
    double		rayDirX;
    double		rayDirY;
    double		deltaDistX;
    double		deltaDistY;
    int			stepX;
    int			stepY;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;	
	int			lineHeight;
	int			side;
	double		hitX;
	double		hitY;
}				t_ray;

/* camera */

/* functions */
int     cub_error(char const *msg, void (*f)(), void *ptr);

/* parser */
int		cub_parser(char *input, t_scene *scene, t_cub *c);
int		cub_loadscene(int fd, t_scene *scene, t_cub *c);
int		cub_evalfile(int fd, t_load *load);
int             cub_evalline(int fd, t_load *load,  char *line, char **parts);
int		cub_psprites(t_load *load, char **parts);
int		cub_pfloor(t_load *load, char *line, int type);
int		cub_pwalls(t_load *load, char **parts, int type);
int		cub_readmap(int fd, t_load *load,  char *line);
int		cub_loadmap(t_load *load, t_map *map);
int     cub_loadwalls(t_load *l, t_scene *sc, void *mlx);
int     cub_loadfile(t_image *img, void *mlx, char *path);


/* draw */
int cub_loadplayer(t_load *load, t_player *player);
int cub_init(t_cub *c, t_scene *sc);
void cub_draw_minimap(t_cub *c, t_ray *ray);
int cub_draw(t_cub *c);
void cub_draw_screen(t_cub *c, t_ray *ray);
	
/* draw_pixel*/
void    cub_mpp(t_image *data, int x, int y, int color);
/* init_point*/
t_point cub_point(double x, double y, int colour);
/* draw_line */
void    cub_line(t_point a, t_point b, t_image *data);

/*ray*/
t_ray *cub_ray(t_scene *d,  int width, double fov);

/* draw_walls*/
int     cub_piinte(t_fp *fp);

/* free */
void    cub_dfree(char ***tofree);
void    cub_freelextra(t_lextra **node);


/* helper */
char    **cub_splits(char const *str, char const *set);
int		cub_countparts(char **parts);
int		cub_isnumber(char const *str);
char	**cub_cparr(char **parts);


/* hooks */
int		motion_hook(int x, int y, t_cub *d);
int		key_down_hook(int keycode, t_cub *d);
int		key_up_hook(int keycode, t_cub *d);
int		mouse_buttons(int button, int x, int y, t_scene *d);

int		exited(t_cub *d);
int		entered(t_cub *d);

/* player */
void	init_player(t_cub *c);
void	rotate_player(t_cub *c, int direction);
void	handle_player(t_cub *c);

/* weapon */
void	init_weapon(t_cub *c);
void 	draw_weapon(t_cub *c);

/* free willis */
int	mlx_terminate(t_cub *d);

#endif
