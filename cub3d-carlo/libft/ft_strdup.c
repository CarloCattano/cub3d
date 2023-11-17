/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:36:00 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/04 15:06:16 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	len;

	len = ft_strlen(s1) + 1;
	duplicate = malloc(sizeof(char) * len);
	if (!duplicate)
		return (0);
	duplicate = ft_memcpy(duplicate, s1, len);
	return (duplicate);
}
