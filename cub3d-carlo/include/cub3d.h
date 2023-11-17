
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "key_codes.h"
# include "constants.h"

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
}				t_point;

typedef struct s_image
{
	void		*img;
	char		*pix;
	int			line_lenght;
	int			bpp;
	int			endian;
	int 		x;
	int 		y;
}				t_image;

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
}				t_ray;


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

// typedef struct s_scene 
// {

// }
typedef struct s_3d
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_image			mmap;
	int 			worldMap[24][24];
	t_player		player;
	int				color;
	float			fps;
	double			planeX;
	double			planeY;
	double			time;
	double			oldTime;
}					t_data;


void				init_img(t_data *d);
int					init_variables(t_data *d);
int					mlx_terminate(t_data *d);
/*
	HOOKS
*/

int					motion_hook(int x, int y, t_data *d);
int					key_down_hook(int keycode, t_data *d);
int					key_up_hook(int keycode, t_data *d);
int					mouse_buttons(int button, int x, int y, t_data *d);

int					mlx_terminate(t_data *d);

void				draw(t_data *d);
void				handle_player(t_data *d);

void				rotate_player(t_data *d, int direction);

void				init_player(t_data *d);
void				draw_minimap(t_data *d);
/*
	UTILS
*/
int					ft_max(int n, int m);
int					ft_clip(int n, int min, int max);
void				my_mlx_pixel_put(t_data *d, int x, int y, int color);
int					ft_rgb2hex(t_rgb rgb);

int					read_file();

int					exited(t_data *d);
int					entered(t_data *d);

void 				draw_weapon(t_data *d);
void 				init_weapon(t_data *d);


#endif
