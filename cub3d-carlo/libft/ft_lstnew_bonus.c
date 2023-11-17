/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccattano <ccattano@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:00:17 by ccattano          #+#    #+#             */
/*   Updated: 2022/12/04 15:02:57 by ccattano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*val;

	val = (t_list *)malloc(sizeof(t_list));
	if (!val)
		return (val = NULL);
	val->next = NULL;
	val->content = content;
	return (val);
}
