/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_isctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:49:13 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:36:58 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_isctype(char ctype, t_printf *form)
{
	if (ctype == 'c' || ctype == 's' || ctype == 'p' || ctype == 'd'
		|| ctype == 'i' || ctype == 'u' || ctype == 'x'
		|| ctype == 'X' || ctype == '%')
	{
		form->ctype = ctype;
		return (1);
	}
	return (0);
}
