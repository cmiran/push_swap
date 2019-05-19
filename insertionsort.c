/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:57:06 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/19 21:05:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void		swap_me(t_lst **a, t_lst **b)
{
	if (a)
	{
		if ((*a)->val > (*a)->next->val)
		{
			SA(a);
		}
	}
	else if (b)
	{
		if ((*b)->val < (*b)->next->val)
		{
			SB(b);
		}
	}
}


void	insertionsort(t_lst **a, t_lst **b, int lo, int hi)
{
	int		i;

	i = lo;
//	lo == 0 ? lo++ : 0;
	hi == (*(*a)->n) ? i += 1 : 0;
	while (i < hi)
	{
		while (i >= lo && (*a)->next->val < (*a)->val)
		{
			SA(a);
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
