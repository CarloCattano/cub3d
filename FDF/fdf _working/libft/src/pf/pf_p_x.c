/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:36:25 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:46:42 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_p_x(va_list arg, t_printf *form)
{
	unsigned int	value;
	int				i;
	int				lenvx;

	i = 0;
	value = va_arg(arg, unsigned int);
	lenvx = pf_lenvx(value, form);
	if (form->flgmns)
	{
		pf_pvx(value, form);
		i += pf_printwidth(form, lenvx);
	}
	else
	{
		i += pf_printwidth(form, lenvx);
		pf_pvx(value, form);
	}
	return (i + lenvx);
}
