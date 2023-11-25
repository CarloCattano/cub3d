/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:56:10 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:45:38 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*wb1;
	unsigned char	*wb2;

	wb1 = (unsigned char *)b1;
	wb2 = (unsigned char *)b2;
	if (len)
	{
		while (len >= 1 && *wb1 == *wb2)
		{
			if (len == 1)
				return (0);
			len--;
			wb1++;
			wb2++;
		}
		return (*wb1 - *wb2);
	}
	else
		return (0);
}
