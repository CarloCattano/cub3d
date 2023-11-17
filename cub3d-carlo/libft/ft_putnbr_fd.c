/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:32:36 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/02 09:44:32 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	char	c;

	if (num == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(fd, "-", 1);
			num = -num;
			ft_putnbr_fd(num, fd);
		}
		else if (num < 10)
		{
			c = num + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(num / 10, fd);
			c = (num % 10) + '0';
			write(fd, &c, 1);
		}
	}
}
