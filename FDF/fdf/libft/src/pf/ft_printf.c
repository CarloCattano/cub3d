/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:47:21 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 14:50:17 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"	

static int	ft_hprintf(int *counter, char temp)
{
	(*counter)++;
	ft_putchar_fd(temp, 1);
	return (1);
}

int	ft_printf(const char *formstr, ...)
{
	int			counter;
	va_list		arg;
	const char	*temp;
	t_printf	form;

	if (!formstr)
		return (-1);
	temp = formstr;
	counter = 0;
	va_start(arg, formstr);
	while (*temp)
	{	
		if (*temp != '%')
			temp += ft_hprintf(&counter, *temp);
		else
		{
			pf_resform(&form);
			temp += pf_setform(temp, &form, arg);
			counter += pf_process(arg, &form);
		}
	}						
	va_end(arg);
	return (counter);
}
