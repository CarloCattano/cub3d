/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:06:16 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:51:26 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_process(va_list arg, t_printf *form)
{
	if (!form->ctype)
		return (0);
	if (form->ctype == '%')
		return (pf_p_percent());
	if (form->ctype == 'c')
		return (pf_p_c(arg, form));
	if (form->ctype == 's')
		return (pf_p_s(arg, form));
	if (form->ctype == 'p')
		return (pf_p_p(arg, form));
	if (form->ctype == 'd' || form->ctype == 'i')
		return (pf_p_id(arg, form));
	if (form->ctype == 'u')
		return (pf_p_u(arg, form));
	if (form->ctype == 'x' || form->ctype == 'X')
		return (pf_p_x(arg, form));
	return (0);
}
