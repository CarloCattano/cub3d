/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:40:43 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 20:35:25 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	c;

	c = 0;
	d_len = ft_strlen(dst);
	if (dstsize > 0 && dstsize > d_len)
	{
		while (src[c] != '\0' && c < dstsize - d_len - 1)
		{
			dst[d_len + c] = src[c];
			c++;
		}
		dst[d_len + c] = '\0';
		return (d_len + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + dstsize);
}
