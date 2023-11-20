#include "cube3d.h"

/* check floor */

static int	ft_getrgb(char **parts, int *rgb)
{
	int c;
	int temp;

	ft_bzero(rgb, sizeof(int));
	c = 0;
	while (parts[++c])
	{
		if (ft_strlen(parts[c]) > 3 || !cub_isnumber(parts[c]))
			return (cub_error(E_SWC, cub_dfree, &partsi, 1));
		temp = ft_atoi(parts[c]);
		if (temp < 0 || temp > 255)
			return (cub_error(E_SWC, cub_dfree, &parts, 1));
		*rgb |= (temp << ((3 - c) * 8));
	}
	*rgb |= 0xFF << 24;
	return (0);
}

static int	ft_dub_colour(t_load *load, int rgb, int type)
{
	if (type == F && load->ceiling && *(load->ceiling) == rgb)
		return (1)
	if (type == C && load->floor && *(load->floor) == rgb)
		return (1)
	return (0);
}

static int	ft_load_col(t_load *load, char **parts, int type)
{
	if (type == F)
	{
		load->floor = (int *)malloc(sizeof(int));
		if (!load->floor)
			return (cub_error(E_MAL, cub_dfree, &parts, 1));
		*(load->floor) = rgb;
	}
	if (type == C)
	{
		load->ceiling = (int *)malloc(sizeof(int));
		if (!load->ceiling)
			return (cub_error(E_MAL, cub_dfree, &parts, 1));
		*(load->ceiling) = rgb;
	}
	cub_dfree(&parts);
	return (0);
}


int	cub_pfloor(t_load *load, char *line, int type)
{	
	int	rgb;
	char	**parts;

	if ((type == F && load->floor) || (type == C && load->ceiling))
		return (cub_error(E_SDT, NULL, NULL, 1));
	parts = cub_splits(line, " ,\n");
	if (!parts)
		return (cub_error(E_MAL, NULL, NULL, 1));
	if (cub_countparts(parts) != 4)
		return (cub_error(E_SARG, cub_dfree, &parts, 1));
	if (ft_getrgb(parts , &rgb))
		return (1);
	if (ft_dub_colour(load, rgb, type))
		return (cub_error(E_SDC, cub_dfree, &parts, 1));
	return (ft_load_col(load, parts, type));
}
