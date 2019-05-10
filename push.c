/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:25:22 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/10 17:37:14 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_lst **lst1, t_lst **lst2)
{
	t_lst	*start;
	t_lst	*tmp;

	if (*lst1)
	{
		if (!*lst2)
		{
			*lst2 = init_node();
			(*lst2)->val = (*lst1)->val;
			tmp = *lst1;
			*lst1 = (*lst1)->next;
			free(tmp);
		}
		else
		{
			start = init_node();
			start->val = (*lst1)->val;
			start->next = *lst2;
			*lst2 = start;
			tmp = *lst1;
			*lst1 = (*lst1)->next;
			free(tmp);
		}
	}
}
