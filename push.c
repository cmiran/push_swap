/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:25:22 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/09 18:24:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_lst **lst1, t_lst **lst2)
{
	t_lst	*start;
	t_lst	*tmp;

	if (lst1)
	{
		start = *lst2;
		tmp = *lst1;
		*lst1 = (*lst1)->next;
		while ((*lst2)->next)
			*lst2 = (*lst2)->next;
		(*lst2)->next = init_node();
		*lst2 = (*lst2)->next;
		(*lst2)->val = tmp->val;
		*lst2 = start;
		free(tmp);
	}
}
