/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/18 14:32:27 by cmiran           ###   ########.fr       */
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

void	push_back(t_lst **a, t_lst **b, int n)
{
//	printf("PUSH-BACK--\n");
	while (n--)
	{
		PA(b, a);
//		n > 1 && n % 3 ? swap_me(0, b) : 0;
//		PRINT(a, b);
	}
//	printf("\n");
//	printf("END--PUSH-BACK--\n");
}

void	which_rotate(t_lst **a, t_lst **b, int n)
{
//	printf("------------WHICH--ROTATE---\n");	
//	printf("n : %d\n", n);

	while (n > 1 && n--)
	{
		RRA(a);
//		PRINT(a, 0);
//		printf("\n");
	}
	RRR(a, b);
//	PRINT(a, 0);
//	printf("-------END-WHICH--ROTATE---\n\n");	
}

void	go_to_position(t_lst **a, int lo, int y)
{
	static int	n = 0;
	int			tmp;

	tmp = lo;
	lo -= n;
	n = tmp;
//	printf("lo : %i\n", lo);
	while (lo--)
	{
		if (y)
		{
//			swap_me(a, 0);
			RA(a);
		}
		else
		{
//			swap_me(a, 0);
			RRA(a);
		}
//			PRINT(a, 0);	
//			printf("\n");
	}
//	printf("---END--GO-TO\n\n");
}

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	long	pivot;
	int		i;
	int		j;
	
//	printf("PARTITION---------------------------------\n");
//	printf("lo : %d, hi : %d\n\n", lo, hi);
	go_to_position(a, lo, 1);
//	swap_me(a, 0);	
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
//		PRINT(a, b);
	}
	which_rotate(a, b, (hi - i));
	push_back(a, b, (*(*b)->n));
	(i - lo) == 1 ? 0 : go_to_position(a, lo, 0);
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
