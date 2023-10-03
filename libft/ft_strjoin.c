/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:06:28 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/04 15:06:26 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		t_len;
	char	*n_str;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	t_len = len1 + len2;
	n_str = malloc(t_len + 1);
	if (!(n_str))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		n_str[i] = s1[i];
		i++;
	}
	while (i < t_len)
	{
		n_str[i] = s2[i - len1];
		i++;
	}
	n_str[t_len] = '\0';
	return (n_str);
}
