/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_evalline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/07 17:45:23 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_gettype(char *c)
{
		if (!c)
			return (0);
		if (ft_isdigit( *c)
			return (MAP);
		if (!ft_strcmp(c, "NO"))
			return (NO);
		if (!ft_strcmp(c, "SO"))
			return (SO);
		if (!ft_strcmp(c, "WE"))
			return (WE);
		if (!ft_strcmp(c, "EA"))
			return (EA);
		if (!ft_strcmp(c, "F"))
			return (F);
		if (!ft_strcmp(c, "C"))
			return (C);
		if (!ft_strcmp(c, "S")|| !ft_strcmp(c, "W") || !ft_strcmp(c, "D") || \
			!ft_strcmp(c, "E"))
			return (S);
		return (0);
}
int ft_count_parts(char **parts)
{
	int c;
	while ((*parts)++)
		c++
	return (c);
}


int ft_get_rgb(int count, char **parts, int *rgb)
{
	int rgb[3];
	int c;
	int k;
	char **values;

	c = 1;
	k = 0;

	while (count--)
	{
		if (c >= 4)
			return ()
		values = ft_split(parts + c, ',');
		while (values[k++])
		{	
			if (c < 4)
				rgb[c - 1] = 
			
			if ( c++ == 4)
				return (); 
		}	


	} 



}





/* check floor */
int	ft_floor(t_load *load, char **parts, int type)
{	
	int count;
	int rgb;
		
	if ((type == F && load->floor) || type == C && load->ceiling)
		return (cub_error(SAMEARG, NULL, NULL));
	count = ft_count_parts(parts + 1);
	if ( !count || count >3)
		return (cub_error(MANYARG, NULL ,NULL));
	if ( 
			
}






int		cub_evalline(int fd, t_load *load,  char *line, char **parts)
{
	int type;
	
	type = ft_gettype(parts[0]);
	if (!type)
		return (1);
	if (type == S)
		return (ft_sprite(load, parts));
	if (type <= EA)
		return (ft_walls(load, parts);
	if (type <= C)
		return (ft_floor(load, parts, type);
	return (cub_readmap (fd, load, line));
}			
	






}	
