#include "cube3d.h"

/* check floor */

int	ft_getrgb(char **parts, int *rgb)
{
	int c;
	int temp;

	ft_bzero(rgb, sizeof(int));
	c = 0;
	while (parts[++c])
	{	
		if (ft_strlen(parts[c]) > 3 || !cub_isnumber(parts[c])) 				
			return (cub_error(SCENEWCOL, cub_dfree, &parts));
		temp = ft_atoi(parts[c]);
		if (temp < 0 || temp > 255)
			return (cub_error(SCENEWCOL, cub_dfree, &parts));
		*rgb |= (temp << ((3 - c) * 8));  	
	}
	*rgb |= 0xFF << 24;
	return (0);	  
}	



int	cub_pfloor(t_load *load, char *line, int type)
{	
	int rgb;
	char **parts;
		
	if ((type == F && load->floor) || (type == C && load->ceiling))
		return (cub_error(SAMEARG, NULL, NULL));
	parts = cub_splits(line, " ,\n");
	if (!parts)
		return (cub_error(E_MAL, NULL, NULL));	
	if (cub_countparts(parts) != 4)
		return (cub_error(SCENEARG, cub_dfree, &parts));
	if (ft_getrgb(parts , &rgb))
		return (1);
	if ((type == F && load->ceiling && *(load->ceiling) == rgb) || (type == C && load->floor && *(load->floor) == rgb))
		return (cub_error(SCENECOL, cub_dfree, &parts));
	if (type == F)
	{
		load->floor = (int *)malloc(sizeof(int));
		if (!load->floor)
			return (cub_error(E_MAL, cub_dfree, &parts));
		*(load->floor) = rgb;
	}
	if (type == C)				
	{	
		load->ceiling = (int *)malloc(sizeof(int));
		if (!load->ceiling)
			return (cub_error(E_MAL, cub_dfree, &parts));
		*(load->ceiling) = rgb;
	}
	cub_dfree(&parts);
	return (0);
}
