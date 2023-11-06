/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_resform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:44:56 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 11:48:24 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	pf_resform(t_printf *form)
{
	form->flgmns = 0;
	form->flgzr = 0;
	form->flgpls = 0;
	form->flgspc = 0;
	form->flghsh = 0;
	form->width = 0;
	form->per = 0;
	form->perb = 0;
	form->star = 0;
	form->ctype = 0;
	form->clen = 0;
}
