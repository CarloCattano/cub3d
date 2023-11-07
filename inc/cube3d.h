/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 12:09:57 by jstrotbe         ###   ########.fr       */
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
# define ERROR_FILE_WRONG " FILE IS NOT RIGHT CINFIGUERD"
# define ERROR_MALOC	"MALLOC_FAIL"


/* structs */

typedef e_type t_type;
typedef s_scene t_scene;
typedef s_image	t_image;
typedef s_map t_map;
typedef	s_sprites t_sprites;
typedef s_lextra	t_lextra;
typedef s_extra		t_extra;

enum e_type
{
	NOT = 0,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	COMMENT = 99

}

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
}

struct s_image
{
	void		*img;
	char		*pix;
	int			line_lenght;
	int			bpp;
	int			endian;
	int 		x;
	int 		y;
}

struct s_sprites
{
	t_vector			position;
	t_image				sprites;
	double				z;
	double				dist;
	int					hdiv;
	int					vdiv;
	t_sprites			*next;
}

struct	s_extra
{
	char	*key;
	t_image	extra;
	t_extra *next;	
}	


struct s_lextra
{
	char *key;
	char *path;		
	char **value;
}


struct	s_load
{
	char *wall[4];
	int *c_floor;
	int *c_ceiling;	
	t_list *map;
	t_list *extra;
}

struct s_map
{
	t_size				height;
	t_size				width;
	char				**val;
}	t_map;


/* functions */
int     cub_error(char const *msg, void (*f)(), void *ptr);

/* parser */
int		cub_parser(char *input, t_scene *scene);
int		cub_loadscene(int fd, t_scene *scene);


#endif	
