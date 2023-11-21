#include "cub3d.h"

char **ft_cparr(char **parts)
{
	int amount;
	char **cp;
	int i;
	
	amount = cub_countparts(parts);
	cp = malloc(sizeof(char *) * (amount + 1)); 
	if (!cp)
		return (NULL);
	i = -1;
	while (parts[++i])
	{
		cp[i] = ft_strdup(parts[i]);	
		if (!cp[i])
			return (cub_dfree(&cp), NULL);
	}
	cp[i] = NULL;	
	return (cp);
}


t_lextra *ft_error(char *msg, t_lextra *node)
{
	ft_printf("Error\n%s\n", msg);
	if (node)
		cub_freelextra(&node);
	return (node);
}

int ft_evsprit(char **value)
{
	(void)value;
	return (0);
}


t_lextra	*ft_lextra(char **parts)
{
	t_lextra *nextra;
	int t;
	
	if ((!ft_strncmp(parts[0], "S", 1)  && cub_countparts(parts) < 4) ||  (ft_strncmp(parts[0], "S", 1) && cub_countparts(parts) != 2))
		return (ft_error(SCENEARG, NULL));
	t = open(parts[1], O_RDONLY);
	if (t == -1)
		return (ft_error(SOPEN, NULL)); 
	nextra = malloc(sizeof(t_lextra));
	if (!nextra)
		return (ft_error(E_MAL, NULL));
	ft_bzero(nextra, sizeof(t_lextra));
	nextra->key = ft_strdup(parts[0]);
	nextra->path = ft_strdup(parts[1]);
	nextra->value = ft_cparr(parts + 2);
	if ( !nextra->key || !nextra->path || !nextra->value)
		return (ft_error(E_MAL, nextra)); 	
	if (!ft_strncmp(nextra->key, "S", 1) && ft_evsprit(nextra->value))
		return (ft_error(E_MAL, nextra));
	return (nextra);		
}



int	cub_psprites(t_load *load, char **parts)
{
	t_list *nnode;

	nnode = ft_lstnew(ft_lextra(parts));
	if (!nnode)
		return (cub_error(E_MAL, NULL, NULL));
	if (!nnode->content)
		return (1); 
	ft_lstadd_back(&(load->extra), nnode);
	return (0);	
}

