/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:01:06 by jstrotbe          #+#    #+#             */
/*   Updated: 2022/12/08 20:07:48 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(unsigned int n)
{
	int	c;

	c = 1;
	while (n > 9)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static unsigned int	ft_helper_itoa(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	int				negative;
	int				size;
	char			*nstr;
	int				i;
	unsigned int	bn;

	i = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	bn = ft_helper_itoa(n);
	size = ft_count(bn) + negative;
	nstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (0);
	if (negative == 1)
		nstr[0] = '-';
	while (i < size - negative)
	{
		nstr[size - i++ - 1] = (bn % 10) + '0';
		bn /= 10;
	}
	nstr[size] = 0;
	return (nstr);
}
