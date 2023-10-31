/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:50:26 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:49:36 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// behavior with ** undifined 
int	pf_setper(char per, t_printf *form, va_list arg)
{
	if (per == '*' || ft_isdigit(per))
	{
		if (per == '*' && !(form->per) && !(form->star))
		{
			form->per = va_arg(arg, int);
			form->star = 1;
		}
		if (ft_isdigit(per) && !(form->star))
			form->per = form->per * 10 + (per - '0');
		return (1);
	}
	else
		return (0);
}
