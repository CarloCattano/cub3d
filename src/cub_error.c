/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:13:11 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/21 17:48:55 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_error(char const *msg, void (*f)(), void *ptr)
{
	if (f)
	{
		f(ptr);
	}
	ft_printf("Error\n%s\n", msg);
	return (1);
}



