/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:18:13 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/06 13:42:59 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube3d.h"


int	cub_parser(char *input)
{
	int fd;
	size_t len;
	if (!input)
		return (cub_error(ERROR_FILE, NULL ,NULL));
	len = ft_strlen(input);
	if (len < 4 || ft_strncmp(input + len -4, ".cub", 4))
		return (cub_error(ERROR_CUB, NULL, NULL));
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (
	return (0);
	



}

