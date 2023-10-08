/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:35:08 by ccattano          #+#    #+#             */
/*   Updated: 2023/10/08 20:20:24 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_format(va_list args, const char *format, int *len, int *i);
int		ft_printf(const char *str, ...);
void	p_char(int c, int *count);
void	p_num(int n, int *count);
void	p_str(const char *str, int *count);
void	p_hex(unsigned long long n, int *count);
void	p_upperhex(unsigned int n, int *count);
void	p_ptr(void *p, int *count);
void	p_unum(unsigned int n, int *count);

#endif
