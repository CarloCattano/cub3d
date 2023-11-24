#!/bin/sh 

cc -o your_program_name main.c weapon_animation.c -lmlx -L../minilibx-linux -I./minilibx-linux -I../inc/ -lft -L../libft -I../libft/inc/ -L./ -I. -lXext -lX11 -lm -lz -ggdb3 

