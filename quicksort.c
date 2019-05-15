/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/15 21:38:16 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	dumbsort(t_lst **a, t_lst **b)
{
	int	i;

	i = 0;
	while (i < (*(*a)->n))	
	{
		if ((*a)->val > (*a)->next->val)
			SA(a);
		RA(a);
		i++;
	}
	i = 0;
	while (i < (*(*b)->n) - 1)	
	{
		if ((*b)->val > (*b)->next->val)
			SB(b);
		RB(b);
		i++;
	}
	RB(b);
}
*/
/*
void	rotate2(t_lst **a, int lo)
{
	if (lo)
	{
		if (lo > ((*(*a)->n) / 2))
		{
			lo = ((*(*a)->n) / 2);
//			printf("---ROTATE1\n");
			while (lo--)
			{
				RA(a);
//				PRINT(a, 0);	
//				printf("\n");
			}
//			printf("---END--ROTATE1\n\n");
		}
		else
		{
//			printf("---ROTATE1\n");
			while (lo--)
			{
				RRA(a);
//				PRINT(a, 0);	
//				printf("\n");
			}
//			printf("---END--ROTATE1\n\n");
		}
	}
}

void	rotate1(t_lst **a, int lo)
{
	if (lo)
	{
		if (lo > ((*(*a)->n) / 2))
		{
			lo = ((*(*a)->n) / 2);
//			printf("---ROTATE1\n");
			while (lo--)
			{
				RRA(a);
//				PRINT(a, 0);	
//				printf("\n");
			}
//			printf("---END--ROTATE1\n\n");
		}
		else
		{
//			printf("---ROTATE1\n");
			while (lo--)
			{
				RA(a);
//				PRINT(a, 0);	
//				printf("\n");
			}
//			printf("---END--ROTATE1\n\n");
		}
	}
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
	
//	rotate1(a, lo);
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

	if ((*a)->val > (*a)->next->val)
	{
		SA(a);
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
//	printf("k : %d\n", k);
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

//	rotate2(a, lo);	
	if (n)
	{
//		printf("---ROTATE2\n");
		while (n--)
		{
			RRA(a);
//			PRINT(a, b);
//			printf("\n");
		}
//		printf("---END--ROTATE2\n\n");
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
//		printf("LOL1\n");
//		**n = p;
		quicksort(a, b, p, hi);
	}
//	printf("LOL2\n");
	return (*a);
}
/*
t_lst	*quicksort2(t_lst **a, t_lst **b, int lo, int hi, int **n)
{
	int	p;
	
	if (lo < hi - 1)
	{
		p = partition(a, b, lo, hi);
//		quicksort(a, b, lo, p, n);
		quicksort(a, b, p, hi, n);
	}
	return (*a);
}*/
