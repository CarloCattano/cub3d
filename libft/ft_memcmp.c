/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:32:50 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/02 15:41:46 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1buff;
	const unsigned char	*s2buff;
	size_t				i;

	i = 0;
	s1buff = (const unsigned char *)s1;
	s2buff = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1buff[i] != s2buff[i])
			return (s1buff[i] - s2buff[i]);
		i++;
	}
	return (0);
}
