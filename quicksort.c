/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/17 13:38:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_me(t_lst **a, t_lst **b)
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

void	push_back(t_lst **a, t_lst **b, int n)
{
	while (n--)
	{
		PA(b, a);
		n > 1 && n % 3 ? swap_me(0, b) : 0;
//		PRINT(a, b);
	}
//	printf("\n");
//	printf("END---SWAP--PUSH---\n");
}

void	which_rotate(t_lst **a, t_lst **b, int k, int hi)
{
//	printf("PARTITION--ROTATE---\n");	
//	printf("k : %d, hi : %i\n", k, hi);
//	if (k != hi)
//	{
		if (k > ((*(*a)->n) / 2))
		{
			k = (*(*a)->n) - k;
			while (k--)
			{
				RA(a);
//				PRINT(a, 0);
//				printf("\n");
			}
			RRB(b);
//			PRINT(0, b);
//			printf("\n");
		}
		else
		{
			k -= 1;
			while (k > 0 && k--)
			{
				RRA(a);
//				PRINT(a, 0);
//				printf("\n");
			}
			RRR(a, b);
//			PRINT(a, b);
		}
//	}
//	printf("END-PARTITION--ROTATE---\n");	
}

void	go_to_position(t_lst **a, int lo, int k, int y)
{
	printf("---GO-TO\n");
	static int	n = 0;

	if (lo > ((*(*a)->n) / 2))
	{
		lo = (*(*a)->n) - lo;
		while (lo--)
		{
			if (y)
			{
				RRA(a);
			}
			else
			{
//				lo % 6 ? swap_me(a, 0) : 0;
				RA(a);
			}
//			PRINT(a, 0);	
//			printf("\n");
		}
	}
	else
	{
		printf("n : %i, lo : %i\n", n, lo);
		if (k)
			n ? n += (lo - n) : (n = lo);
		printf("n : %i\n", n);
		n ? lo = lo - n - 1 : 0;
		while (lo > 0 && lo--)
		{
			if (y)
			{
//				lo % 7 ? swap_me(a, 0) : 0;
				RA(a);
			}
			else
			{
				RRA(a);
			}
//			PRINT(a, 0);	
//			printf("\n");
		}
	}
/*	}
	else
	{*/

	printf("---END--GO-TO\n");
}

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	long	pivot;
	int		i;
	int		j;
	static int	k = 1;
	
	printf("PARTITION---------------------------------\n");
	printf("lo : %d, hi : %d\n\n", lo, hi);
	go_to_position(a, lo, (k == hi), 1);
	while (k > 1)
		k--;
	k += lo;
	lo % 6 ? swap_me(a, 0) : 0;
//	swap_me(a, 0);
	pivot = (*a)->val;
	i = lo;
	j = lo;
	while (j++ < hi)
	{
//		printf("j : %i\n", j);
		if ((*a)->val <= pivot)
		{
			PB(a, b);
			i++;
		}
		else
		{
			RA(a);
			k++;
		}
//		PRINT(a, b);
	}
	printf("k : %i, hi : %i\n", k, hi);
	which_rotate(a, b, (j - i - 1), hi);
	push_back(a, b, (*(*b)->n));
	go_to_position(a, lo, (k == hi), 1);
	printf("i : %i\n---END\n\n", i);
	return (i);
}

t_lst	*quicksort(t_lst **a, t_lst **b, int lo, int hi)
{
	int	p;
	
	if (lo < hi - 1)
	{
		p = partition(a, b, lo, hi);
		quicksort(a, b, lo, p);
		quicksort(a, b, p, hi);
	}
	return (*a);
}
