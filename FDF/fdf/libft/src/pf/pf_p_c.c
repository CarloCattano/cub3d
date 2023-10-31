/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:02:04 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:39:18 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_p_c(va_list arg, t_printf *form)
{
	int		i;
	int		lenvc;
	char	value;

	value = (char)va_arg(arg, int);
	i = 0;
	lenvc = 1;
	if (form->flgmns)
	{
		ft_putchar_fd(value, 1);
		i += pf_printwidth(form, lenvc);
	}
	else
	{
		i += pf_printwidth(form, lenvc);
		ft_putchar_fd(value, 1);
	}
	return (i + lenvc);
}
