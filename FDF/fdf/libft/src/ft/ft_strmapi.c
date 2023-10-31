/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:15:05 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 13:11:27 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*nstr;
	size_t				ls;
	unsigned int		i;

	i = 0;
	ls = ft_strlen(s);
	nstr = (char *)malloc(sizeof(char) * (ls + 1));
	if (!nstr)
		return (NULL);
	while (i < ls)
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
