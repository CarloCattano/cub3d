
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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17
};


typedef struct ctrl_states 
{
	int upDown;
	int leftRight;
}				t_ctrl_states;

typedef struct s_2d
{
    int	x;
    int	y;
}					t_2d;

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

typedef struct s_fpoint
{
	float			x;
	float			y;
}				t_fpoint;

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

typedef struct player
{
    t_point     	pos;
    t_fpoint		dir;
	int				speed;
	t_ctrl_states 	ctrl;
}               t_player;

typedef struct s_3d
{
	t_image			img;
	int				color;
	int				menu;
    t_player        player;
	float			fps;
}					t_3d;

void				init_img(t_3d *d);
void				settings(t_3d *d);

/*
	HOOKS
*/

int					motion_hook(int x, int y, t_3d *d);
int					key_down_hook(int keycode, t_3d *d);
int					key_up_hook(int keycode, t_3d *d);
int					mouse_scaling_hook(int button, int x, int y, t_3d *d);

int					terminate(t_3d *d);

void				draw(t_3d *d);

void				draw_line(t_3d *d, t_point p1, t_point p2, int color);

void                init_player(t_3d *d);
void                drawPlayer(t_3d *d);

/*
	UTILS
*/
int					ft_max(int n, int m);
int					ft_clip(int n, int min, int max);
void				print_debug(t_3d *d, char *str);
void				mlx_pixel_put_image(t_image *img, int x, int y, int color);

#endif 
