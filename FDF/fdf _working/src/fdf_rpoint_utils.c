/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rpoint_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:12:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/03 18:33:41 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_new_rpoint(t_rpoint **lldata, t_trans *stemp)
{
	t_rpoint	*temp;

	temp = fdf_new_node(stemp->x, stemp->y, stemp->z, stemp->trgb);
	if (!temp)
		fdf_clearrpoint(lldata);
	fdf_add_front(lldata, temp);
	if (stemp->trgb)
		stemp->trgb = 0;
}

t_rpoint	*fdf_new_node(int x, int y, int z, int colour)
{
	t_rpoint	*lstnew;

	lstnew = (t_rpoint *)malloc(sizeof(t_rpoint));
	if (!lstnew)
		return (NULL);
	lstnew->x = x;
	lstnew->y = y;
	lstnew->z = z;
	lstnew->trgb = colour;
	lstnew->next = NULL;
	return (lstnew);
}

t_rpoint	*fdf_lstnode(t_rpoint *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	fdf_clearrpoint(t_rpoint **lst)
{
	t_rpoint	*temp;
	t_rpoint	*curr;

	if (lst && *lst)
	{
		curr = *lst;
		while (curr)
		{
			temp = curr->next;
			free(curr);
			curr = temp;
		}
		*lst = NULL;
	}
}

void	fdf_add_front(t_rpoint **lst, t_rpoint *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
