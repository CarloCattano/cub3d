#include "cunde3d.h"


int cub_pwalls(t_load *load, char **parts, int type)
{
	int fd;

	if (cub_countparts(parts) != 2)
		return (cub_error(SCENEARG, NULL, NULL));
	if (load->wall[type - 1])
		return (cub_error(SAMEARG, NULL, NULL));
	fd = open(parts[1], O_RDONLY);
	if (fd == -1)
		return (perror("ERROR OPEN"), cub_error(ERROR_FILE_OPEN, NULL, NULL));	 
	load->wall[type - 1] = ft_strdup(parts[1]);
	if (!load->wall[type - 1])
		return (close(fd), cub_error(E_MAL, NULL, NULL);
	close(fd);	 
}

