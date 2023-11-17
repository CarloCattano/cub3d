/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:30:03 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/11 19:12:41 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(long num)
{
	size_t	n_digits;

	n_digits = 0;
	if (num < 0)
	{
		n_digits++;
		num = -num;
	}
	while (num >= 1)
	{
		n_digits++;
		num /= 10;
	}
	return (n_digits);
}

static char	*generate_string(char *res, long num, int l, int neg)
{
	if (num != 0)
		res = malloc(sizeof(char) * (l + 1));
	else
		return (res = ft_strdup("0"));
	if (!res)
		return (0);
	neg = 0;
	if (num < 0)
	{
		neg++;
		num = -num;
	}
	res[l] = '\0';
	while (--l)
	{
		res[l] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		res[0] = '-';
	else
		res[0] = (num % 10) + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*res;
	long	num;
	int		neg;

	num = n;
	l = number_of_digits(num);
	res = 0;
	neg = 0;
	res = generate_string(res, num, l, neg);
	if (!(res))
		return (0);
	return (res);
}
