/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:39:31 by ccattano          #+#    #+#             */
/*   Updated: 2023/01/29 14:15:52 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_format(va_list args, const char *format, int *len, int *i)
{
	if (format[*i] == '%')
		p_char(format[*i], len);
	else if (format[*i] == 'c')
		p_char(va_arg(args, int), len);
	else if (format[*i] == 's')
		p_str(va_arg(args, char *), len);
	else if (format[*i] == 'd' || format[*i] == 'i')
		p_num(va_arg(args, int), len);
	else if (format[*i] == 'u')
		p_unum(va_arg(args, unsigned int), len);
	else if (format[*i] == 'x' )
		p_hex(va_arg(args, unsigned int), len);
	else if (format[*i] == 'X')
		p_upperhex(va_arg(args, unsigned int), len);
	else if (format[*i] == 'p')
		p_ptr(va_arg(args, void *), len);
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		size;

	va_start(args, str);
	i = 0;
	len = 0;
	if (!str)
		return (0);
	size = ft_strlen(str);
	while (str[i] && i < size)
	{
		if (str[i] != '%')
			p_char(str[i++], &len);
		else if (i < size)
		{
			i++;
			ft_format(args, str, &len, &i);
		}
	}
	va_end (args);
	return (len);
}
