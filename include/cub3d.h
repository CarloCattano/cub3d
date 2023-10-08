
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include "ft_printf.h"
# include <math.h>
# include "key_codes.h"
# define WIDTH 680
# define HEIGHT 680
# define BLOCK 42

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17
};


typedef struct ctrl_states 
{
	int		up_down;
	int		left_right;
	int		turn;
}			t_ctrl_states;

typedef struct s_2d
{
	int		x;
	int		y;
}			t_2d;

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

typedef struct s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct s_image
{
	void		*mlx;
	void		*win;
	int			*image;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;

typedef struct player
{
	t_point			pos;
	t_dpoint		dir;
	int				speed;
	t_ctrl_states	ctrl;
}					t_player;

typedef struct s_3d
{
	t_image			img;
	int				color;
	int				menu;
	t_player		player;
	float			fps;
}					t_data;

void				init_img(t_data *d);
void				settings(t_data *d);

/*
	HOOKS
*/

int					motion_hook(int x, int y, t_data *d);
int					key_down_hook(int keycode, t_data *d);
int					key_up_hook(int keycode, t_data *d);
int					mouse_scaling_hook(int button, int x, int y, t_data *d);

int					terminate(t_data *d);

void				draw(t_data *d);

void				draw_line(t_data *d, t_point p1, t_point p2, int color);

void				init_player(t_data *d);
void					draw_player(t_data *d);

/*
	UTILS
*/
int					ft_max(int n, int m);
int					ft_clip(int n, int min, int max);
void				print_debug(t_data *d, char *str);
void				my_mlx_pixel_put(t_data *d, int x, int y, int color);

#endif 
