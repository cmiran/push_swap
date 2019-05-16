/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/16 18:28:07 by cmiran           ###   ########.fr       */
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

void	which_rotate(t_lst **a, t_lst **b, int k, int hi)
{
//	printf("PARTITION--ROTATE---\n\n");	
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
//			PRINT(a, b);
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

void	go_to_position(t_lst **a, int lo, int y)
{
	if (lo)
	{
		if (lo > ((*(*a)->n) / 2))
		{
			lo =  (*(*a)->n) - lo;
//			printf("---ROTATE1\n");
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
				if (y)
				{
					RA(a);
				}
				else
				{
					RRA(a);
				}
//				PRINT(a, 0);	
//				printf("\n");
			}
//			printf("---END--ROTATE1\n\n");
		}
	}
}

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	intmax_t	pivot;
	int			i;
	int			j;
	int			k;
	
//	printf("PARTITION---------------------------------\n");
//	printf("lo : %d, hi : %d\n\n", lo, hi);
	
	go_to_position(a, lo, 1);
	if ((*a)->val > (*a)->next->val)
	{
		SA(a);
//		PRINT(a, 0);	
//		printf("\n");
	}
	pivot = (*a)->val;
	i = lo;
	j = lo;
	k = 0;
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
	which_rotate(a, b, k, hi);
	j = (*(*b)->n);
//	printf("\nj : \n%i\n", j);
	while (j--)
	{
		PA(b, a);
//		PRINT(a, b);
	}
//	printf("\n");
	go_to_position(a, lo, 0);	

//	printf("i : %i\n---END\n\n", i);*/
	
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
