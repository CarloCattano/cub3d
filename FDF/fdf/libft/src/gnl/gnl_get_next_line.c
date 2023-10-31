/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:33 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/01/26 13:29:17 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_free(char **alloc)
{
	if (*alloc)
	{
		free(*alloc);
		*alloc = NULL;
	}
}

int	gnl_strlen(char *store)
{
	int	i;

	i = 0;
	if (store)
		while (store[i])
			i++;
	return (i);
}

int	gnl_readfile(int fd, char *buf, char **store)
{
	int	wb;

	wb = read(fd, buf, BUFFER_SIZE);
	if (wb >= 0)
	{
		buf[wb] = 0;
		return (wb);
	}
	gnl_free(store);
	return (-1);
}

char	*gnl_line(char *buf, char **store, int fd)
*{
	int	rb;
	int	index;

	index = 0;
	rb = BUFFER_SIZE;
	if (!*store)
	{
		rb = gnl_readfile(fd, buf, store);
		if (rb <= 0)
			return (NULL);
		*store = gnl_strdup(buf, rb, store);
	}
	index = gnl_check(*store, index, rb);
	while (index == -1 && *store)
	{
		index = gnl_strlen(*store);
		rb = gnl_readfile(fd, buf, store);
		if (rb < 0)
			return (NULL);
		if (rb)
			gnl_store(store, buf, index, rb);
		index = gnl_check(*store, index, rb);
	}
	return (gnl_split(store, index));
}

char	*get_next_line(int fd)
{
	static char		*store = NULL;
	char			*line;
	char			*buf;

	if (0 >= BUFFER_SIZE || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (fd < 0)
	{	
		if (fd == -2)
			gnl_free(&store);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		gnl_free(&store);
		return (NULL);
	}
	line = gnl_line(buf, &store, fd);
	gnl_free(&buf);
	return (line);
}
