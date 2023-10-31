/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:49:04 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 10:51:43 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*wb;

	if (!len)
		return (NULL);
	wb = (unsigned char *)b;
	i = 0;
	while (i < len && wb[i] != (unsigned char)c)
	{
		i++;
		if (i == len)
			return (NULL);
	}
	return ((void *)wb + i);
}
