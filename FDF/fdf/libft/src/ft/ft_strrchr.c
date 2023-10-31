/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:38 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 10:35:28 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	lens;

	lens = ft_strlen(s);
	if (!lens && (char)c)
		return (NULL);
	while ((lens > 0) && s[lens] != (char)c)
	{
		lens--;
		if (lens == 0 && s[lens] != (char)c)
			return (NULL);
	}
	return ((char *)&s[lens]);
}
