/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:12:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/24 18:07:03 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_me(t_lst **a, t_lst **b)
{
	if (a)
	{
		if ((*a)->val > (*a)->next->val)
		{
			SA(a);
			return (1);
		}
	}
	else if (b)
	{
		if ((*b)->val < (*b)->next->val)
		{
			SB(b);
			return (1);
		}
	}
	return (0);
}

void	insertionsort(t_lst **a, t_lst **b, int lo, int hi)
{
	int		i;

	i = lo;
	hi > 7 && hi == (*(*a)->n) ? i++ : 0;
	while (i < hi)
	{
		while (i >= lo && swap_me(a, 0))
		{
			RRA(a);
			i--;
		}
		RA(a);
		i++;
	}
	if (hi == (*(*a)->n))
	{
		RA(a);
	}
}
