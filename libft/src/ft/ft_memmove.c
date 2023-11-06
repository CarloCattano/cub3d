/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:49:34 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/07 19:15:28 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *) dest;
	sr = (unsigned char *) src;
	if (dest > src)
		while (len--)
			de[len] = sr[len];
	if (dest < src)
		while (len--)
			*de++ = *sr++;
	return (dest);
}		
