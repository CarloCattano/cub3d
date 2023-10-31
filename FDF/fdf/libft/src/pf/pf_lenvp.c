/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lenvp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:57:09 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:37:24 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hlenvp(t_printf *form, int *lenvp)
{
	if (form->flgpls || form->flgspc)
		(*lenvp)++;
	if (form->flgzr)
	{
		while (*lenvp < form->width -2)
			(*lenvp)++;
		form->flgzr = *lenvp - form->clen;
	}
}

int	pf_lenvp(unsigned long long value, t_printf *form)
{
	int	lenvp;

	if (form->ctype)
	{	
		lenvp = pf_count_base_ull(value, 16);
		form->clen = lenvp;
		if (!form->perb && !form->flgmns)
			ft_hlenvp(form, &lenvp);
		else
		{
			while (lenvp < form->per)
				lenvp++;
			if (form->flgpls || form->flgspc)
				lenvp++;
		}
	}
	else
		lenvp = 3;
	return (lenvp + 2);
}
