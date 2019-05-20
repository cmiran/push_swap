/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/20 03:54:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_lst **a, t_lst **b, int n)
{
/*	int	n;
	
i	n = (*(*b)->n);
	if (n < 10)
		insertionsort(b, lo, hi*/
	while (n--)
	{
		PA(b, a);
	}
}

void	rotate_back(t_lst **a, t_lst **b, int n)
{
	while (n > 1 && n--)
	{
		RRA(a);
	}
	RRR(a, b);
}

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	static int	first = 1;
	long		pivot;
	int		i;
	int		j;
	
//	go_to_index(a, lo, 1);
	swap_me(a, 0);
	pivot = (*a)->val;
	i = lo;
	j = lo;
	while (j++ < hi)
	{
		if ((*a)->val <= pivot)
		{
			PB(a, b);
			i++;
		}
		else
		{
			RA(a);
		}
	}
	first ? first-- : rotate_back(a, b, (hi - i));
//	(*(*b)->n) < 8 ? insertionsort_b(b, 0, (*(*b)->n)) : 0;
	push_back(a, b, (*(*b)->n));
//	go_to_index(a, lo, 0);
	return (i);
}

void	quicksort(t_lst **a, t_lst **b, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		if ((hi - lo) <= 7) // <= Lucky number
		{
			insertionsort(a, lo, hi);
		}
		else
		{
			p = partition(a, b, lo, hi);
			quicksort(a, b, lo, p);
			quicksort(a, b, p, hi);
		}
	}
}
