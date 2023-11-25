/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:49:02 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:52:06 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	pf_putnbr_fd_base(unsigned int nb, int fd, unsigned int base, char form)
{
	if (nb >= base)
	{
		pf_putnbr_fd_base(nb / base, fd, base, form);
		pf_putnbr_fd_base(nb % base, fd, base, form);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + 48, fd);
		else
		{
			if (form == 'x')
				ft_putchar_fd(nb + 87, fd);
			else
				ft_putchar_fd(nb + 55, fd);
		}
	}
}
