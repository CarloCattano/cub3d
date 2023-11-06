/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:48:23 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 15:14:06 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// behavior with ** undifined 
int	pf_setwidth(char width, t_printf *form, va_list arg)
{
	if (width == '*' || ft_isdigit(width))
	{
		if (width == '*' && !(form->width) && !(form->star))
		{
			form->width = va_arg(arg, int);
			form->star = 1;
		}
		if (ft_isdigit(width) && !(form->star))
			form->width = form->width * 10 + (width - '0');
		return (1);
	}
	else
		return (0);
}
