/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lenvu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:51 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:38:21 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_lenvu(unsigned int value, t_printf *form)
{
	int	lenvu;

	lenvu = 0;
	lenvu += pf_count_base(value, 10);
	if (form->perb && !form->per && !value)
		lenvu = 0;
	form->clen = lenvu;
	if (form->flgzr && !form->perb && !form->flgmns)
	{
		while (lenvu < form->width)
			lenvu++;
		form->flgzr = lenvu - form->clen;
	}
	else
	{
		while (lenvu < form->per)
			lenvu++;
	}
	return (lenvu);
}
