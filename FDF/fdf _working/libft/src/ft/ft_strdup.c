/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:44:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 10:57:08 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*nstr;
	int		c;

	c = 0;
	nstr = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!nstr)
		return (NULL);
	while (src[c])
	{
		nstr[c] = src[c];
		c ++;
	}
	nstr[c] = '\0';
	return (nstr);
}
