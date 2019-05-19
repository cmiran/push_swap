/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/19 22:11:45 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	go_to_index(t_lst **a, int lo, int y)
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
}*/
long	get_optimal_pivot(t_lst **a, long pivot)
{
/*	if (!pivot || (*a)->val > pivot)
	{*/
		swap_me(a, 0);
		return ((*a)->val);
/*	}
	else if (pivot < 0)
		return (pivot * 2);
	else
		return (pivot / 2);*/
}
void	push_back(t_lst **a, t_lst **b, int n)
{
//	printf("PUSH-BACK--\n");
	while (n--)
	{
		PA(b, a);
//		PRINT(a, b);
	}
//	printf("\n");
//	printf("END--PUSH-BACK--\n");
}

void	rotate_back(t_lst **a, t_lst **b, int n, int j)
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

int	partition(t_lst **a, t_lst **b, int lo, int hi)
{
	static int	first = 1;
	static long	pivot = 0;
	int		i;
	int		j;
	
//	printf("PARTITION---------------------------------\n");
//	printf("lo : %d, hi : %d\n\n", lo, hi);
//	go_to_index(a, lo, 1);
	pivot = get_optimal_pivot(a, pivot);
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
	first ? first-- : rotate_back(a, b, (hi - i), j);
	push_back(a, b, (*(*b)->n));
//	printf("i - lo : %d\n", (i - lo));
//	go_to_index(a, lo, 0);
//	printf("i : %i\n---END\n\n", i);
	return (i);
}

t_lst	*quicksort(t_lst **a, t_lst **b, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		if ((hi - lo) <= 5) 
		{
			insertionsort(a, b, lo, hi);
		}
		else
		{
			p = partition(a, b, lo, hi);
			quicksort(a, b, lo, p);
			quicksort(a, b, p, hi);
		}
	}
	return (*a);
}
