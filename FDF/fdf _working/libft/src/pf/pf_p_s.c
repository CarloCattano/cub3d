/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:56:05 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:42:27 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_p_s(va_list arg, t_printf *form)
{
	char	*value;
	int		i;
	int		lenvs;

	i = 0;
	value = va_arg(arg, char *);
	if (!value)
	{
		form->ctype = 0;
		value = "(null)";
	}
	lenvs = pf_lenvs(value, form);
	if (form->flgmns)
	{
		pf_pvs(value, form);
		i += pf_printwidth(form, lenvs);
	}
	else
	{
		i += pf_printwidth(form, lenvs);
		pf_pvs(value, form);
	}
	return (i + lenvs);
}
