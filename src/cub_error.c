/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:13:11 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/06 11:32:23 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube3d.h"




int		cub_error(char const *msg, void (*f)(), void *ptr)
{
	if (f)
	{
		f(ptr);
	}
	ft_printf("Error\n%s\n", msg);
	return (1);
}



