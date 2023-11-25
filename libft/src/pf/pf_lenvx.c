/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lenvx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:38:56 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/25 10:50:26 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_lenvx(unsigned int value, t_printf *form)
{
	int	lenvx;

	lenvx = 0;
	lenvx += pf_count_base(value, 16);
	if (form->perb && !form->per && !value)
		lenvx = 0;
	form->clen = lenvx;
	if (form->flgzr && !form->perb && !form->flgmns)
	{
		while (lenvx < form->width)
			lenvx++;
		form->flgzr = lenvx - form->clen;
		if (form->flghsh)
			form->flgzr -= 2;
	}
	else
	{
		while (lenvx < form->per)
			lenvx++;
	}
	if (form->flghsh && !form->flgzr && value)
		lenvx += 2;
	return (lenvx);
}
