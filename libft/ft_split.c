/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:34:35 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/12 15:38:41 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_malloc(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	if (!s[0])
		return (0);
	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

static void	get_next(char **next, size_t *next_len, char c)
{
	size_t	i;

	*next += *next_len;
	*next_len = 0;
	i = 0;
	while (**next && **next == c)
		(*next)++;
	while ((*next)[i])
	{
		if ((*next)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*next_word;
	size_t	next_len;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_len = 0;
	while (i < count_words(s, c))
	{
		get_next(&next_word, &next_len, c);
		str[i] = (char *)malloc(sizeof(char) * (next_len + 1));
		if (!str[i])
			return (ft_free_malloc(str));
		ft_strlcpy(str[i], next_word, next_len + 1);
		i++;
	}
	str[i] = NULL;
	return (str);
}
