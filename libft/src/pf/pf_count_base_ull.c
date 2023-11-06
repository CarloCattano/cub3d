/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_count_base_ull.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:43:53 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:36:32 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_count_base_ull(unsigned long long value, unsigned long long base)
{
	int	i;

	i = 1;
	if (base)
	{
		while (value > base - 1)
		{
			i++;
			value = value / base;
		}
	}
	return (i);
}
