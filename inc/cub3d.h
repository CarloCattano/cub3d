/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/26 18:16:39 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* extern */
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <time.h>

/* our */
# include "constants.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "key_codes.h"
# include "libft.h"
# include "msg.h"
# include "struct.h"
# include <fcntl.h>

/* functions */
int			cub_error(char const *msg, char er, void (*f)(), void *ptr);

/* parser */
int			cub_parser(char *input, t_sc *sc, t_cub *c);
int			cub_loadsc(int fd, t_sc *sc, t_cub *c);
int			cub_evalfile(int fd, t_load *load);
int			cub_evalline(int fd, t_load *load, char *line, char **parts);
int			cub_psprites(t_load *load, char **parts);
int			cub_pfloor(t_load *load, char *line, int type);
int			cub_pwalls(t_load *load, char **parts, int type);
int			cub_readmap(int fd, t_load *load, char *line);
int			cub_loadmap(t_load *load, t_map *map);
int			cub_loadwalls(t_load *l, t_sc *sc, void *mlx);
int			cub_loadfile(t_image *img, void *mlx, char *path);
int			cub_checkmap(char **val, t_load *load);
void		cub_loadply(t_load *load, t_ply *ply);
void		cub_pload(t_load *l);
void		cub_loadcfpl(t_sc *sc, t_load *load);
int			cub_loadextra(t_load *l, t_sc *sc, void *mlx);

/* draw */
int			cub_init(t_cub *c, t_sc *sc);
void		cub_draw_minimap(t_cub *c, t_ray *ray);
int			cub_draw(t_cub *c);
void		cub_draw_screen(t_cub *c, t_ray *ray);

void		cub_mpp(t_image *data, int x, int y, int color);
t_point		cub_point(double x, double y, int colour);
void		cub_line(t_point a, t_point b, t_image *data);

t_ray		*cub_ray(t_sc *d, int width, double fov);

/* draw_walls*/
int			cub_piinte(t_fp *fp);

/* free */
void		cub_dfree(char ***tofree);
void		cub_freelextra(t_lextra **node);
void		cub_freesc(t_sc *sc, void *mlx);

/* helper */
char		**cub_splits(char const *str, char const *set);
int			cub_countparts(char **parts);
int			cub_isnumber(char const *str);
char		**cub_cparr(char **parts);

/* hooks */
int			motion_hook(int x, int y, t_cub *d);
int			key_down_hook(int keycode, t_cub *d);
int			key_up_hook(int keycode, t_cub *d);
int			mouse_buttons(int button, int x, int y, t_cub *d);

int			exited(t_cub *d);
int			entered(t_cub *d);

/* ply */
void		rotate_ply(t_cub *c, int direction);
void		handle_ply(t_cub *c);

/* wp */
void		draw_wp(t_cub *c);

/* free willis */
int			mlx_terminate(t_cub *d);
void		get_wall_orientation(t_ray *ray, t_cub *c, t_fp *fp);

void		add_frame(t_cub *c);

u_int32_t	color_pixel(u_int32_t *pixel);
void		clamp(int *color, u_int8_t min, u_int8_t max);
u_int32_t	cub_darken(u_int32_t argb, double factor);

#endif
