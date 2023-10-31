/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:31:49 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:39:56 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_p_id(va_list arg, t_printf *form)
{
	int	value;
	int	i;
	int	lenvid;

	i = 0;
	value = va_arg(arg, int);
	lenvid = pf_lenvid(value, form);
	if (form->flgmns)
	{
		pf_pvid(value, form);
		i += pf_printwidth(form, lenvid);
	}
	else
	{
		i += pf_printwidth(form, lenvid);
		pf_pvid(value, form);
	}
	return (i + lenvid);
}
