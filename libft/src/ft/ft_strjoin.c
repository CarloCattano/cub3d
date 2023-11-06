/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:07:32 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 11:24:28 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	s1l;
	size_t	s2l;
	size_t	i1;
	size_t	i2;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	i1 = 0;
	i2 = 0;
	nstr = (char *)malloc(sizeof(char) * (s1l + s2l + 1));
	if (!nstr)
		return (NULL);
	while (i1 < s1l)
		nstr[i1++] = *s1++;
	while (i2 < s2l)
		nstr[i1 + i2++] = *s2++;
	if (!s1l && !s2l)
		nstr[0] = '\0';
	else
		nstr[i1 + i2] = '\0';
	return (nstr);
}
