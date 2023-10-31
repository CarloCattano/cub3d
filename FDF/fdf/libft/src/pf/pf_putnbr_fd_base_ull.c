/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd_base_ull.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:46:44 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:43:43 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	pf_putnbr_fd_base_ull(unsigned long long nb, int fd,
	unsigned long long base, char form)
{
	if (nb >= base)
	{
		pf_putnbr_fd_base_ull(nb / base, fd, base, form);
		pf_putnbr_fd_base_ull(nb % base, fd, base, form);
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
