/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:13:11 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 13:46:49 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	cub_error(char const *msg, char er, void (*f)(), void *ptr)
{
	if (f)
	{
		f(ptr);
	}
	if (er)
		ft_printf("%s\n", E_);
	if (er == 2)
		perror("ERROR OPEN");
	ft_printf("%s\n", msg);
	return (1);
}
