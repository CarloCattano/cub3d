#include "cub3d.h"



int	ft_checkload(t_load *l)
{
	if (!l->wall[0] || !l->wall[1] || !l->wall[2] || !l->floor || !l->ceiling)
		return (1);
	return (0);
}




int	cub_readmap(int fd, t_load *load,  char *line)
{
	char **check;
	t_list *node;
	
	if (ft_checkload(load)
		return (cub_error(E_T, free, line);
	while (line)
	{
		check = split(line, " \n");
		if (!check)
			return (cub_error(E_MAL, free, line));
		if (!check[0][0] || !ft_isdigit(check[0][0]))
			return (free(line), cub_error(E_M, cub_dfree, &check);
		node = ft_lstnew(line);
		if (!node)
			return (free(line), cub_error(E_MAL, cub_dfree, &check));
		ft_lstadd_back(node);
		cub_dfree(&check);
		line = get_next_line(fd);		
	}
	return (2);
}
