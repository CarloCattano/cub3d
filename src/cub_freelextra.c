#include "cube3d.h"

void 	cub_freelextra(lextra **node)
{
	if (*node)
	{
		if ((*node)->key)
			free((*node)->key);
		if ((*node)->path)
			free((*node)->path);
		if ((*node)->values)
			cub_dfree(&((*node)->values));
		free (*node);
	}
	*node = NULL;
}	

