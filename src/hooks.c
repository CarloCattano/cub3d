#include "../include/cub3d.h"

/*
	mouse pos 
*/

int	motion_hook(int x, int y, t_data *d)
{
	(void)d;
	(void)x;
	(void)y;
	return (1);
}

int	mouse_scaling_hook(int k, int x, int y, t_data *d)
{
	(void)d;
	if ((k == 1 || k == 2)
		&& (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == MOUSE_LEFT || k == MOUSE_RIGHT)
		{
		}
	}
	return (1);
}
