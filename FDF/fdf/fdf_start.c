/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:35:06 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/05 17:49:35 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_start(t_fdf *fdf)
{
	fdf_setup(fdf);
	ft_printf("%s\n", TXT_BE);
	ft_printf("%s\n%s\n%s\n%s\n%s\n", TXT_ST, TXT_MV, TXT_RO, TXT_ZO, TXT_HI);
	ft_printf("%s\n%s\n%s\n%s\n", TXT_CE, TXT_RE, TXT_PE, TXT_COL);
	ft_printf("%s\n", TXT_EN);
	fdf_draw(fdf);
}
