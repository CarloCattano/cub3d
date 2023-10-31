/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lenvs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:09:34 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:39:07 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_lenvs(char *value, t_printf *form)
{
	int		lenvs;
	char	*temp;

	temp = value;
	lenvs = 0;
	while (*temp++)
		lenvs++;
	if (lenvs > form->per && form->perb)
	{
		if (!form->ctype)
			form->per = 0;
		lenvs = form->per;
	}
	form->clen = lenvs;
	return (lenvs);
}
