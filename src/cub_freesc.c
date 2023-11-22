#include "cube3d.h"



/* freesc has also to free mlx and dteroy display */
void	cub_freesc(t_sc *sc, void *mlx)
{
	int i;

	if (sc->floor)
		mlx_destroy_image(mlx, sc->floor.img);
	if (sc->ceiling)
		mlx_destroy_image(mlx, sc->ceiling.img);
	i = -1;
	while (++i < 4)
	{
		if (sc->wall[i].img)
			mlx_destroy_image(mlx, sc->wall[i].img);
	}				
}
