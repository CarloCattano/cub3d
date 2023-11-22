#include "cube3d.h"

static t_lextra	*ft_error(char *msg, t_lextra *node, char er)
{
	if (er)
		ft_printf("%s\n", E_);
	ft_printf("%s\n", msg);
	if (node)
		cub_freelextra(&node);
	return (node);
}

/* need  atod */
static int	ft_evsprit(char **value)
{
	(void)value;
	return (0);
}

static int	ft_check_extras(char **parts)
{
	if (!ft_strncmp(parts[0], "S", 1)  && cub_countparts(parts) < 4)
		return (0);
	if (ft_strncmp(parts[0], "S", 1) && cub_countparts(parts) != 2)
		return (0);
	return (1);
}

static t_lextra	*ft_lextra(char **parts)
{
	t_lextra	*nextra;
	int		t;

	if (!ft_check_extras(parts))
		return (ft_error(E_SARG, NULL, 1));
	t = open(parts[1], O_RDONLY);
	if (t == -1)
		return (ft_error(E_SOTF, NULL, 1));
	nextra = malloc(sizeof(t_lextra));
	if (!nextra)
		return (ft_error(E_MAL, NULL, 1));
	ft_bzero(nextra, sizeof(t_lextra));
	nextra->key = ft_strdup(parts[0]);
	nextra->path = ft_strdup(parts[1]);
	nextra->value = cub_cparr(parts + 2);
	if ( !nextra->key || !nextra->path || !nextra->value)
		return (ft_error(E_MAL, nextra, 1));
	if (!ft_strncmp(nextra->key, "S", 1) && ft_evsprit(nextra->value))
		return (ft_error(E_SWARG, nextra, 0));
	return (nextra);
}

int	cub_psprites(t_load *load, char **parts)
{
	t_list	*nnode;

	nnode = ft_lstnew(ft_lextra(parts));
	if (!nnode)
		return (cub_error(E_MAL,1, NULL, NULL));
	if (!nnode->content)
		return (1); 
	ft_lstadd_back(&(load->extra), nnode);
	return (0);
}
