/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:37:42 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/03 09:51:29 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_cpy;
	const char	*s_cpy;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d_cpy = (char *)dst;
	s_cpy = (const char *)src;
	while (n-- > 0)
		d_cpy[n] = s_cpy[n];
	return (dst);
}
