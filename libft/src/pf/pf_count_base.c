/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_count_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:51 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:35:57 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_count_base(unsigned int value, unsigned int base)
{
	int	i;

	i = 1;
	if (base)
	{
		while (value > base -1)
		{
			i++;
			value = value / base;
		}
	}
	return (i);
}
