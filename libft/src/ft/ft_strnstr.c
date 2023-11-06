/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:07 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 11:47:04 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char	*little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] && little[j] && big[i + j] == little[j]
				&& i + j < len)
			{
				if (!little[j + 1])
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
