/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lenvid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:40:26 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:36:35 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_hlenvid(int value, t_printf *form, int *lenvid)
{
	if (value < 0 || form->flgpls || form->flgspc)
		(*lenvid)++;
	if (form->flgzr)
	{
		while (*lenvid < form->width)
			(*lenvid)++;
		if (value < 0 || form->flgpls || form->flgspc)
			form->flgzr = *lenvid - form->clen;
		else
			form->flgzr = *lenvid - form->clen + 1;
	}
}

int	pf_lenvid(int value, t_printf *form)
{
	int				lenvid;
	unsigned int	temp;

	temp = pf_itoui(value);
	lenvid = pf_count_base(temp, 10);
	if (form->perb && !form->per && !value)
		lenvid = 0;
	form->clen = lenvid;
	if (!form->perb && !form->flgmns)
		ft_hlenvid(value, form, &lenvid);
	else
	{
		while (lenvid < form->per)
			lenvid++;
		if (value < 0 || form->flgpls || form->flgspc)
			lenvid++;
	}
	return (lenvid);
}
