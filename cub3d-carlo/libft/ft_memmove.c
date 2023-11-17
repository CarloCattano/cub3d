/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:59:22 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/02 15:40:20 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_pointer;
	char	*src_pointer;

	dst_pointer = (char *)dst;
	src_pointer = (char *)src;
	if (dst == src)
		return (dst);
	if (src_pointer < dst_pointer)
	{
		while (len--)
			*(dst_pointer + len) = *(src_pointer + len);
		return (dst);
	}
	while (len--)
		*dst_pointer++ = *src_pointer++;
	return (dst);
}
