/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:37:47 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/11 19:32:11 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_size;
	char	*ret_str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	str_size = ft_strlen(s + start);
	if (str_size < len)
		len = str_size;
	ret_str = (char *)malloc((len + 1) * sizeof(char));
	if (!(ret_str))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret_str[i] = s[start + i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
