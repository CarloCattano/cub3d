#include "cube3d.h"



int	ft_checkload(t_load *l)
{
	if (!l->wall[0] || !l->wall[1] || !l->wall[2] || !l->floor || !l->ceiling)
		return (1);
	return (0);
}

/*
	max x value
	check if map is valid 
	- only valid symbols
	
	ply : x / y / direction; only one;
	



*/
int ft_initpl(t_load *load)
{
	load->xpl = malloc(sizeof(int));
	load->ypl = malloc(sizeof(int));
	if (!load->xpl || !load->ypl)
		return (cub_error(E_MAL, NULL, NULL));
	return (0);
}



int	ft_setply(t_load *load, char d, int c)
{
	if (load->xpl)
		return (cub_error(M_P, NULL, NULL));
	if (ft_initpl(load))
		return (1);
	*load->ypl = load->ymap;
	*load->xpl = c;
	load->dir = d;
	return (0);
}	

int	ft_evalmap(t_load *load, char *line)
{
	char	**check;
	int	c;
		
	check = cub_splits(line, " \n");
	if (!check)
		return (cub_error(E_MAL, NULL, NULL));
	if (!check[0]|| !ft_isdigit(check[0][0]))
		return (cub_error(E_M, cub_dfree, &check));
	cub_dfree(&check);
	c = -1;
	while (line[++c] != '\n')  	
	{
		if (ft_strchr( INMAP , line[c]))
			continue;
		if (ft_strchr(DIRECT, line[c]))
		{
			if (ft_setply(load, line[c], c ))
				return (1);
			continue;
		}
		return (ft_printf("%c ", line[c]), cub_error(E_M, NULL, NULL));
	}
	if (load->xmap < c )
		load->xmap = c ; 
	return (0);
}	

int	cub_readmap(int fd, t_load *load,  char *line)
{
	t_list	*node;
	char	*temp;
	
	if (!line)
		return (cub_error(E_MAL, NULL, NULL));
	if (ft_checkload(load))
		return (cub_error(E_T, free, line));
	while (line)
	{
		if (ft_evalmap(load, line))
		 	return (free(line), 1);
		temp = ft_substr(line, 0, ft_strlen(line) - 1);
		if (!temp)
			return (cub_error(E_MAL, free, line));
		node = ft_lstnew(temp);
		gnl_free(&line);
		if (!node)
			return (cub_error(E_MAL, free, temp));
		ft_lstadd_back(&(load->map) ,node);
		line = get_next_line(fd);
		++load->ymap; 		
	}
	return (2);
}
