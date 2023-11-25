/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:16:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:51:26 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_printwidth(t_printf *form, int lenv)
{
	int	i;

	i = 0;
	while (i < form->width - lenv)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}
