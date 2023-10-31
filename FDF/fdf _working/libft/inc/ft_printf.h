/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:28:02 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:52:35 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_printf
{	
	int		flgmns;
	int		flgzr;
	int		flgpls;
	int		flgspc;
	int		flghsh;
	int		width;
	int		star;
	int		per;
	int		perb;
	char	ctype;
	int		clen;
}	t_printf;

void			pf_resform(t_printf *form);
void			pf_pvs(char *value, t_printf *form);
void			pf_putnbr_fd_base_ull(unsigned long long nb, int fd,
					unsigned long long base, char form);
void			pf_pvp(unsigned long long value, t_printf *form);
void			pf_putnbr_fd_base(unsigned int nb, int fd,
					unsigned int base, char form);
void			pf_pvid(int value, t_printf *form);
void			pf_pvu(unsigned int value, t_printf *form);
void			pf_pvx(unsigned int value, t_printf *form);

int				ft_printf(const char *formstr, ...);
int				pf_setform(const char *temp, t_printf *form, va_list arg);
int				pf_process(va_list arg, t_printf *form);
int				pf_isctype(char ctype, t_printf *form);
int				pf_setflg(char flg, t_printf *form);
int				pf_setwidth(char width, t_printf *form, va_list arg);
int				pf_setper(char per, t_printf *form, va_list arg);
int				pf_process(va_list arg, t_printf *form);
int				pf_p_percent(void);
int				pf_p_c(va_list arg, t_printf *form);
int				pf_printwidth(t_printf *form, int lenv);
int				pf_lenvs(char *value, t_printf *form);
int				pf_p_s(va_list arg, t_printf *form);
int				pf_count_base_ull(unsigned long long value,
					unsigned long long base);
int				pf_lenvp(unsigned long long value, t_printf *form);
int				pf_p_p(va_list arg, t_printf *form);
int				pf_count_base(unsigned int value, unsigned int base);
int				pf_lenvid(int value, t_printf *form);
int				pf_p_id(va_list arg, t_printf *form);
int				pf_lenvu(unsigned int value, t_printf *form);
int				pf_p_u(va_list arg, t_printf *form);
int				pf_lenvx(unsigned int value, t_printf *form);
int				pf_p_x(va_list arg, t_printf *form);

unsigned int	pf_itoui(int value);

#endif
