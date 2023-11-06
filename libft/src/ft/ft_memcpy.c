/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:46:21 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 09:35:20 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*de;
	unsigned char	*sr;

	if (!dest && !src)
		return (NULL);
	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
		*de++ = *sr++;
	return (dest);
}
