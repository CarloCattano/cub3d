/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:51:22 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:46:37 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_cins(char const *ws, char c)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (ws[++i])
	{
		if (ws[i] == c && i > 0)
			if (ws[i - 1] != c)
				count++;
	}
	if (ft_strlen(ws) && ws[i - 1] != c)
		count++;
	return (count);
}

static void	ft_freeall(char	**rs, int irs)
{
	while (irs > 0)
		free(rs[irs--]);
	if (irs == 0)
		free(rs[irs]);
	free(rs);
}

static size_t	ft_lenword(char *ws, unsigned int start, char c)
{
	size_t	lword;

	lword = 0;
	while (ws[start + lword] != c && ws[start + lword])
		lword++;
	return (lword);
}

static char	**ft_into(char **rs, char *ws, char c)
{
	int				irs;
	unsigned int	start;
	size_t			end;

	end = 0;
	start = 0;
	irs = 0;
	while (ws[start])
	{
		end = ft_lenword(ws, start, c);
		if (end)
		{
			rs[irs] = ft_substr(ws, start, end);
			if (!rs[irs++])
			{
				ft_freeall(rs, irs - 2);
				return (NULL);
			}
			start = start + end;
		}
		else
			start++;
	}
	rs[irs] = NULL;
	return (rs);
}

char	**ft_split(char const *s, char c)
{
	int		cins;
	char	**rs;
	char	*ws;

	ws = (char *)s;
	cins = ft_cins(ws, c);
	rs = (char **)malloc((sizeof(char *) * (cins + 1)));
	if (!rs)
		return (0);
	if (cins)
		return (ft_into(rs, ws, c));
	else
	{
		rs[cins] = NULL;
		return (rs);
	}
}
