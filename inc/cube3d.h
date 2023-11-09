/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 17:45:56 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/* inc */
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdbool.h>

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

struct s_image
{
	void		*img;
	char		*pix;
	int			line_lenght;
	int			bpp;
	int			endian;
	int 		x;
	int 		y;
};

struct s_map
{
	size_t				height;
	size_t				width;
	char				**val;
};

struct s_scene
{
	bool		setting[3];
	int			c_floor;
	int			c_ceiling;
	t_image		*floor;
	t_image		*ceiling;
	t_image		walls[4];
	t_map		map;
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
	t_list *map;
	t_list *extra;
};



/* functions */
int     cub_error(char const *msg, void (*f)(), void *ptr);

/* parser */
int		cub_parser(char *input, t_scene *scene);
int		cub_loadscene(int fd, t_scene *scene);
int		cub_evalfile(int fd, t_load *load);
int             cub_evalline(int fd, t_load *load,  char *line, char **parts);
int		cub_psprites(t_load *load, char **parts);
int		cub_pfloor(t_load *load, char *line, int type);
int		cub_pwalls(t_load *load, char **parts, int type);
int		cub_readmap(int fd, t_load *load,  char *line);

/* free */
void    cub_dfree(char ***tofree);
void    cub_freelextra(t_lextra **node);


/* helper */
char    **cub_splits(char const *str, char const *set);
int	cub_countparts(char **parts);
int	cub_isnumber(char const *str);
#endif
