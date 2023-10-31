/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:41:19 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/31 16:47:51 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	gnl_check(char *store, int start, int rb)
{
	if (!store)
		return (-1);
	while (store[start] && store[start] != '\n')
		start++;
	if (!store[start] && rb == BUFFER_SIZE)
		return (-1);
	if (!store[start] && rb < BUFFER_SIZE)
		return (-2);
	return (start);
}

char	*gnl_split(char **store, int index)
{
	char	*nstr;
	char	*temp;
	int		lenstore;

	if (!*store)
		return (NULL);
	lenstore = gnl_strlen(*store);
	if (index == -2)
	{
		temp = NULL;
		nstr = gnl_strdup(*store, lenstore, store);
		if (!nstr)
			gnl_free(store);
	}
	else
	{
		temp = gnl_strdup((*store) + index + 1,
				gnl_strlen((*store) + index + 1), store);
		nstr = gnl_strdup(*store, index + 1, store);
		if (!nstr)
			gnl_free(&temp);
	}
	gnl_free(store);
	*store = temp;
	return (nstr);
}

char	*gnl_strdup(char *str, int len, char **store)
{
	char	*nstr;
	int		c;

	if (!str || !len)
		return (NULL);
	c = 0;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
	{
		gnl_free(store);
		return (NULL);
	}
	while (c < len)
	{
		nstr[c] = str[c];
		c ++;
	}
	nstr[c] = 0;
	return (nstr);
}

void	gnl_store(char **store, char *buf, int lenst, int lenbf)
{
	char	*temp;
	int		i;
	int		i2;

	if (!*store)
		return ;
	i = -1;
	i2 = -1;
	temp = (char *)malloc(sizeof(char) * (lenst + lenbf + 1));
	if (!temp)
	{
		gnl_free(store);
		return ;
	}
	while (++i < lenst)
		temp[i] = *((*store) + i);
	while (++i2 < lenbf)
		temp[i + i2] = buf[i2];
	temp[i + i2] = 0;
	gnl_free(store);
	*store = temp;
}
