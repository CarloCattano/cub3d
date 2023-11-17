/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:51:54 by xcarlo            #+#    #+#             */
/*   Updated: 2023/01/20 19:37:56 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_num(int n, int *count)
{
	if (n == -2147483648)
	{
		p_str("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		p_char(('-'), count);
	}
	if (n >= 10)
		p_num(n / 10, count);
	p_char(n % 10 + 48, count);
}

void	p_unum(unsigned int n, int *count)
{
	if (n >= 10)
	{
		p_unum((n / 10), count);
		p_unum((n % 10), count);
	}
	else
		p_char((n + 48), count);
}

void	p_hex(unsigned long long n, int *count)
{
	if (n >= 16)
	{
		p_hex(n / 16, count);
		p_hex(n % 16, count);
	}
	else if (n < 10)
		p_char((n + 48), count);
	else
		p_char(n + 87, count);
}

void	p_upperhex(unsigned int n, int *count)
{
	if (n >= 16)
	{
		p_upperhex(n / 16, count);
		p_upperhex(n % 16, count);
	}
	else if (n < 10)
		p_char(n + 48, count);
	else
		p_char(n + 55, count);
}

void	p_ptr(void *p, int *count)
{
	if (p != NULL)
	{
		p_str("0x", count);
		p_hex((unsigned long long)p, count);
	}
	if (p == NULL)
		p_str("(nil)", count);
}
