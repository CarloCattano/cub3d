/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pvu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:23:19 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:45:42 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pvu(unsigned int value, t_printf *form)
{
	while (!form->perb && form->flgzr-- > 0)
		ft_putchar_fd('0', 1);
	while (form->clen++ < form->per)
		ft_putchar_fd('0', 1);
	if (!form->perb || (form->perb && form->per)
		|| (form->perb && !form->per && value))
		pf_putnbr_fd_base(value, 1, 10, form->ctype);
}
