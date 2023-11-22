#include "cube3d.h"


void	cub_loadcfpl(t_sc *sc, t_load *load)
{
	sc->c_floor = *load.floor;
	sc->c_ceiling = *load.ceiling;
	sc->plane_x =  - sc->ply.diry;
	sc->plane_y =  sc->ply.dirX;
}

