/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pvx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:50:13 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:46:02 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pvx(unsigned int value, t_printf *form)
{
	if (form->flghsh && value)
	{
		if (form->ctype == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
	while (!form->perb && form->flgzr-- > 0)
		ft_putchar_fd('0', 1);
	while (form->clen++ < form->per)
		ft_putchar_fd('0', 1);
	if (!form->perb || (form->perb && form->per)
		|| (form->perb && !form->per && value))
		pf_putnbr_fd_base(value, 1, 16, form->ctype);
}
