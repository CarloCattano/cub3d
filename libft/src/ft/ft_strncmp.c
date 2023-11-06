/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:46:00 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 10:41:15 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (s1[i] != '\0' && s2[i] != '\0'
			&& i <= n - 1 && s1[i] == s2[i])
			i++;
		if (i == n)
			return ((unsigned char)s1[i - 1] -(unsigned char)s2[i - 1]);
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}
