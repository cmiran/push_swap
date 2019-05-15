/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/15 17:32:26 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_lst	*sort_alst(t_lst *alst, char c)
{
	int	i;
	int	val;

	i = 0;
	while (i < (*alst->n) - 1)	
	{
		if (alst->val > alst->next->val)
			S(alst, c);
		R(alst, c);
		i++;
	}
	return (alst);
}
*/
int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	intmax_t	pivot;
	int			i;
	int			j;
	int			k;
	int			n;
	
//	printf("PARTITION---------------------------------\n");
//	printf("lo : %d, hi : %d\n\n", lo, hi);
	
	n = lo;
	if (lo)
	{
//		printf("---ROTATE1\n");
		while (n--)
		{
			RA(a);
//			PRINT(a, 0);	
//			printf("\n");
		}
		n = lo;
//		printf("---END--ROTATE1\n\n");
	}
	pivot = (*a)->val;
	i = lo;
	j = lo;
	k = -1;
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
	while (k > 0 && k--)
	{
		RRA(a);
//		PRINT(a, 0);
//		printf("\n");
	}
	RRR(a, b);
//	PRINT(a, b);
	j = (*(*b)->n);
//	printf("\nj : \n%i\n", j);
	while (j--)
	{
		PA(b, a);
//		PRINT(a, b);
	}
//	printf("\n");
	if (n)
	{
//		printf("---ROTATE2\n");
		while (n--)
		{
			RRA(a);
//			PRINT(a, b);
//			printf("\n");
		}
//		printf("---END--ROTATE1\n\n");
	}
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
