/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:46:02 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:48:59 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_setflg(char flg, t_printf *form)
{
	if (flg == '-' || flg == '0' || flg == '+' || flg == ' ' || flg == '#')
	{
		if (flg == '-')
			form->flgmns = 1;
		if (flg == '0')
			form->flgzr = 1;
		if (flg == '+')
			form->flgpls = 1;
		if (flg == ' ')
			form->flgspc = 1;
		if (flg == '#')
			form->flghsh = 1;
		return (1);
	}
	else
		return (0);
}
