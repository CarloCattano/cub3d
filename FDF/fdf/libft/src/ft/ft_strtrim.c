/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:42:02 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 12:01:21 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_char_in_set(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	size_t	is1;
	size_t	ls1;
	size_t	i;

	is1 = 0;
	i = 0;
	ls1 = ft_strlen(s1);
	while (s1[is1] && ft_char_in_set(s1[is1], set))
		is1++;
	while (is1 < ls1 - 1 && ft_char_in_set(s1[ls1 - 1], set))
		ls1--;
	nstr = (char *)malloc(sizeof(char) * (ls1 - is1 + 1));
	if (!nstr)
		return (NULL);
	while (is1 < ls1)
		nstr[i++] = s1[is1++];
	nstr[i] = 0;
	return (nstr);
}
