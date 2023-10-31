/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:33:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/09 14:24:34 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;
	size_t	ls;

	if (!s)
		return (NULL);
	i = 0;
	ls = ft_strlen(s);
	if (len > ls)
		len = ls;
	if (start > ls)
		len = 0;
	if (start == ls - 1 && len)
		len = 1;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	if (start < ls)
	{
		while (s[start] && i < len)
			nstr[i++] = s[start++];
	}
	nstr[i] = '\0';
	return (nstr);
}
