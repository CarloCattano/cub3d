/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:40:09 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:55:01 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_setform(const char *temp, t_printf *form, va_list arg)
{
	int	i;

	i = 1;
	if (temp[i])
	{
		while (pf_setflg(temp[i], form))
			i++;
		while (pf_setwidth(temp[i], form, arg))
			i++;
		if (temp [i] == '.')
		{
			form->perb = 1;
			form->star = 0;
			i++;
		}
		while (pf_setper(temp[i], form, arg))
			i++;
		if (pf_isctype(temp[i], form))
			return (++i);
		else
			return (1);
	}
	return (i);
}
