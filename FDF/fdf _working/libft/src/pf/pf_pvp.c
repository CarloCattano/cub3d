/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:06:33 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:44:58 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pvp(unsigned long long value, t_printf *form)
{
	if (form->ctype)
	{
		if (form->flgpls)
			ft_putchar_fd('+', 1);
		if (form->flgspc && !form->flgpls)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		while (!form->perb && form->flgzr-- > 0)
			ft_putchar_fd('0', 1);
		while (form->clen++ < form->per)
			ft_putchar_fd('0', 1);
		pf_putnbr_fd_base_ull(value, 1, 16, 'x');
	}
	else
		ft_putstr_fd("(nil)", 1);
}	
