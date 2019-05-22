/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/21 18:19:58 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*float	find_median(long *tab, int size)
{
	float m;

	m = 0.0;
	sort_int_tab(tab, size);
	if (size % 2 == 0)
		m = (tab[(size - 1) / 2] + tab[size / 2]) / 2.0;
	else
		m = tab[size / 2];
	return (m);
}*/

/*long	median_of_3(t_lst **a, int lo, int hi)
{
	int	i;
	t_lst	*tmp;
	long	m[3];
	
	i = lo;
	tmp = *a;
	while (i++ < hi)
	{
		i == lo ? m[0] = tmp->val : 0;
		i == (hi / 2) ? m[1] = tmp->val : 0;
		i == hi - 1 ? m[2] = tmp->val : 0;
		tmp = tmp->next;
	}
	sort_int_tab(m, 2);
	return (m[1]);
}*/

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

int		partition(t_lst **a, t_lst **b, int lo, int hi)
{
	static int	first = 1;
	long		pivot;
	int			i;
	int			j;
	
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
	push_back(a, b, (*(*b)->n));
	return (i);
}

void	quicksort(t_lst **a, t_lst **b, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		if ((hi - lo) <= 7) // <= Lucky number
			insertionsort(a, lo, hi);
		else
		{
			p = partition(a, b, lo, hi);
			quicksort(a, b, lo, p);
			quicksort(a, b, p, hi);
		}
	}
}
