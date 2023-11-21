#include "cub3d.h"

int	cub_isnumber(char const *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
