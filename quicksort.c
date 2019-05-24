/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/24 15:10:34 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_lst **a, t_lst **b, int n)
{
	while (n--)
	{
		PA(b, a);
	}
}

void	rotate_back(t_lst **a, t_lst **b, int n)
{
	if (n > (*(*a)->n) / 2)
	{
		n = (*(*a)->n) - n;
		while (n--)
		{
			RA(a);
		}
		RRB(b);
	}
	else
	{
		while (n > 1 && n--)
		{
			RRA(a);
		}
		RRR(a, b);
	}
}

long	find_median(t_lst **a, int lo, int hi)
{
	int			i;
	int			j;
	t_lst		*tmp;
	long		m[hi - lo];
	
	i = lo;
	j = 0;
	tmp = *a;
	while (i++ < hi)
	{
		m[j++] = tmp->val;
		tmp = tmp->next;
	}
	sort_int_tab(m, j - 1);
	if ((hi - lo) % 2 != 0)
		return (m[(j / 2) + 1]);
	else
		return (m[(j / 2)]);
}

int		partition(t_lst **a, t_lst **b, int lo, int hi)
{
	static int	first_time = 1;
	long		pivot;
	int			i;
	int			j;
	
	pivot = find_median(a, lo, hi);
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
	first_time ? first_time-- : rotate_back(a, b, (hi - i));
	push_back(a, b, (*(*b)->n));
	return (i);
}

void	quicksort(t_lst **a, t_lst **b, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		if ((hi - lo) <= 7) // <= Lucky number
			insertionsort(a, b, lo, hi);
		else
		{
			p = partition(a, b, lo, hi);
			quicksort(a, b, lo, p);
			quicksort(a, b, p, hi);
		}
	}
}
