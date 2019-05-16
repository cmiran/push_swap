/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/16 19:49:50 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_rotate(t_lst **a, t_lst **b, int k, int hi)
{
//	printf("PARTITION--ROTATE---\n");	
//	printf("k : %d, hi : %i\n", k, hi);
	if (k != hi)
	{
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
	}
//	printf("END-PARTITION--ROTATE---\n");	
}

void	swap_push(t_lst **a, t_lst **b, int n, int y)
{
//	printf("SWAP--PUSH---\n");
	if (y && (*a)->val > (*a)->next->val)
	{
		SA(a);
//		PRINT(a, 0);	
//		printf("\n");
	}
	while (!y && n--)
	{
		PA(b, a);
//		PRINT(a, b);
	}
//	printf("\n");
//	printf("END---SWAP--PUSH---\n");
}

void	go_to_position(t_lst **a, int lo, int y)
{
//	printf("---GO-TO\n");
	if (lo > ((*(*a)->n) / 2))
	{
		lo =  (*(*a)->n) - lo;
		while (lo--)
		{
			if (y)
			{
				RRA(a);
			}
			else
			{
				RA(a);
			}
//			PRINT(a, 0);	
//			printf("\n");
		}
	}
	else
	{
		while (lo--)
		{
			if (y)
			{
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
//	printf("---END--GO-TO\n");
}

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	intmax_t	pivot;
	int			i;
	int			j;
	
//	printf("PARTITION---------------------------------\n");
//	printf("lo : %d, hi : %d\n\n", lo, hi);
	go_to_position(a, lo, 1);
	swap_push(a, b, 0, 1);
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
		}
//		PRINT(a, b);
	}
	which_rotate(a, b, (j - i - 1), hi);
	swap_push(a, b, (*(*b)->n), 0);
	go_to_position(a, lo, 0);	
//	printf("i : %i\n---END\n\n", i);
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
