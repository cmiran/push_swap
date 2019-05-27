/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:12:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/27 18:35:19 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_reverse_sorted(t_lst *b)
{
	while (b->next)
	{
		if (b->val < b->next->val)
			return (0);
		b = b->next;
	}
	return (1);
}

int		swap_me(t_lst **a, t_lst **b)
{
	if (*a)
	{
		if ((*a)->val > (*a)->next->val)
		{
			SA(a);
			return (1);
		}
	}
	else if (*b)
	{
		if ((*b)->val < (*b)->next->val)
		{
			SB(b);
			return (1);
		}
	}
	return (0);
}

void	partition_2(t_lst **a, t_lst **b, int lo, int hi)
{
	int		pivot;
	int		i;

	pivot = find_median(a, lo, hi);
	i = lo;
	while (i < hi)
	{
		if ((*a)->val < pivot)
		{
			PB(a, b);
		}
		else
		{
			RA(a);
		}
		i++;
	}
}

void	lowsort(t_lst **a, t_lst **b, int lo, int hi)
{
	partition_2(a, b, lo, hi);
	while (!is_sorted(*a, 0))
	{
//		swap_me(a, 0);
		RRA(a);
	}
	while (!is_reverse_sorted(*b))
	{
//		swap_me(0, b);
		RRB(b);
	}
	while (*b)
	{
		PA(b, a);
	}
}

/*void	insertionsort2(t_lst **a, t_lst **b, int lo, int hi)
{
	int		i;

	i = lo;
	hi > 7 && hi == (*(*a)->n) ? i++ : 0;
	while (i < hi)
	{
		if (swap_me(a, 0) && i > lo)
		{
			PB(a, b);
			while ((*b)->val < (*a)->val && i >= lo)
			{
				RRA(a);
				i--;
			}
			PA(b, a);
		}
		RA(a);
		i++;
	}
	if (hi == (*(*a)->n))
	{
		RA(a);
	}
}*/

void	insertionsort(t_lst **a, int lo, int hi)
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
