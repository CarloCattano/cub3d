/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:57:26 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:41:04 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_p_p(va_list arg, t_printf *form)
{
	unsigned long long	value;
	int					i;
	int					lenvp;

	i = 0;
	value = va_arg(arg, unsigned long long);
	if (!value)
		form->ctype = 0;
	lenvp = pf_lenvp(value, form);
	if (form->flgmns)
	{
		pf_pvp(value, form);
		i += pf_printwidth(form, lenvp);
	}
	else
	{
		i += pf_printwidth(form, lenvp);
		pf_pvp(value, form);
	}
	return (i + lenvp);
}
