/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:09 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:42:58 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_p_u(va_list arg, t_printf *form)
{
	unsigned int	value;
	int				i;
	int				lenvu;

	i = 0;
	value = va_arg(arg, unsigned int);
	lenvu = pf_lenvu(value, form);
	if (form->flgmns)
	{
		pf_pvu(value, form);
		i += pf_printwidth(form, lenvu);
	}
	else
	{
		i += pf_printwidth(form, lenvu);
		pf_pvu(value, form);
	}
	return (i + lenvu);
}
