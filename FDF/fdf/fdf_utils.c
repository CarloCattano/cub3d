/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:59:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:44:41 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_isspace(int a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == '\f' || a == '\r' || a == ' ')
		return (1);
	else
		return (0);
}

int	ft_isupper(int a)
{
	if (a >= 65 && a <= 90)
		return (1);
	else
		return (0);
}

int	ft_islower(int a)
{
	if (a >= 97 && a <= 122)
		return (1);
	else
		return (0);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}
