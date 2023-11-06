/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pvid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:47:24 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:44:29 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pvid(int value, t_printf *form)
{
	unsigned int	temp;

	temp = pf_itoui(value);
	if (value < 0)
		ft_putchar_fd('-', 1);
	if (form->flgpls && value >= 0)
		ft_putchar_fd('+', 1);
	if (form->flgspc && value >= 0 && !form->flgpls)
		ft_putchar_fd(' ', 1);
	while (!form->perb && --form->flgzr > 0)
		ft_putchar_fd('0', 1);
	while (form->clen++ < form->per)
		ft_putchar_fd('0', 1);
	if (!form->perb || (form->perb && form->per)
		|| (form->perb && !form->per && value))
		pf_putnbr_fd_base(temp, 1, 10, form->ctype);
}
