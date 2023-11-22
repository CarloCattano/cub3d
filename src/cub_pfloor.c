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
			return (cub_error(E_SWC, 1, cub_dfree, &parts));
		temp = ft_atoi(parts[c]);
		if (temp < 0 || temp > 255)
			return (cub_error(E_SWC, 1, cub_dfree, &parts));
		*rgb |= (temp << ((3 - c) * 8));
	}
	*rgb |= 0xFF << 24;
	return (0);
}

static int	ft_dub_colour(t_load *load, int rgb, int type)
{
	if (type == F && load->ceiling && *(load->ceiling) == rgb)
		return (1);
	if (type == C && load->floor && *(load->floor) == rgb)
		return (1);
	return (0);
}

static int	ft_load_col(t_load *load, char **parts, int type, int rgb)
{
	if (type == F)
	{
		load->floor = (int *)malloc(sizeof(int));
		if (!load->floor)
			return (cub_error(E_MAL, 1, cub_dfree, &parts));
		*(load->floor) = rgb;
	}
	if (type == C)
	{
		load->ceiling = (int *)malloc(sizeof(int));
		if (!load->ceiling)
			return (cub_error(E_MAL, 1, cub_dfree, &parts));
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
		return (cub_error(E_SDT, 1, NULL, NULL));
	parts = cub_splits(line, " ,\n");
	if (!parts)
		return (cub_error(E_MAL, 1, NULL, NULL));
	if (cub_countparts(parts) != 4)
		return (cub_error(E_SARG, 1, cub_dfree, &parts));
	if (ft_getrgb(parts , &rgb))
		return (1);
	if (ft_dub_colour(load, rgb, type))
		return (cub_error(E_SDC, 1, cub_dfree, &parts));
	return (ft_load_col(load, parts, type, rgb));
}
