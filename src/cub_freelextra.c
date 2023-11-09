#include "cube3d.h"

void 	cub_freelextra(t_lextra **node)
{
	if (*node)
	{
		if ((*node)->key)
			free((*node)->key);
		if ((*node)->path)
			free((*node)->path);
		if ((*node)->value)
			cub_dfree(&((*node)->value));
		free (*node);
	}
	*node = NULL;
}	

