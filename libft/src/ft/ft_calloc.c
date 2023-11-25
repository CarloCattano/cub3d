/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:50:27 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:42:52 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*nptr;
	size_t	checktotal;

	checktotal = number * size;
	if (number && size && checktotal / number != size)
		return (NULL);
	nptr = (void *)malloc(number * size);
	if (!nptr)
		return (NULL);
	ft_bzero(nptr, number * size);
	return (nptr);
}
