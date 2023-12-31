/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:24:10 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:49:26 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	pf_itoui(int value)
{
	unsigned int	temp;

	if (value < 0)
		temp = value * -1;
	else
	{
		temp = value;
	}
	return (temp);
}
