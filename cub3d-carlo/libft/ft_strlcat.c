/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:45:31 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/04 15:06:29 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	j = 0;
	i = d_len;
	if (size == 0)
		return (s_len);
	if (size < d_len)
		return (s_len + size);
	else
	{
		while (src[j] != '\0' && (d_len + j + 1) < size)
			dest[i++] = src[j++];
		if ((d_len + j) == size && d_len < size)
			dest[i--] = '\0';
		else
			dest[i] = '\0';
		return (s_len + d_len);
	}
}
