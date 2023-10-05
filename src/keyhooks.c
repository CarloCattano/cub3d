
#include "../include/cub3d.h"
#include "key_codes.h"

int	key_down_hook(int k, t_data *d)
{
	if (k == KEY_UP)
		d->player.ctrl.upDown = 1;
	else if (k == KEY_DOWN)
		d->player.ctrl.upDown = -1;
	if (k == KEY_A)
		d->player.ctrl.leftRight = -1;
	else if (k == KEY_D)
		d->player.ctrl.leftRight = 1;
	if (k == KEY_LEFT)
		d->player.ctrl.turn = -1;
	else if (k == KEY_RIGHT)
		d->player.ctrl.turn = 1;

	if (k == KEY_ESCAPE)
		terminate(d);
	return (k);
}

int key_up_hook(int k, t_data *d)
{
	if (k == KEY_UP || k == KEY_DOWN)
		d->player.ctrl.upDown = 0;
	if (k == KEY_A || k == KEY_D)
		d->player.ctrl.leftRight = 0;
	if (k == KEY_LEFT || k == KEY_RIGHT)
		d->player.ctrl.turn = 0;
	return (k);
}
