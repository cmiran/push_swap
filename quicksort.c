/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:05:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/11 21:09:39 by cmiran           ###   ########.fr       */
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
int	partition(t_lst *a, t_lst *b, int lo, int hi)
{
	intmax_t	pivot;
	int	i;
	int	j;
	
	printf("PARTITION---------------------------------\n");
	printf("lo : %d, hi : %d\n", lo, hi);

	pivot = a->val;
	i = lo;
	j = lo;
	while (j++ < hi)
	{
		printf("j : %i\n", j);
		if (a->val <= pivot)
		{
			PB(a, b);
			i++;
		}
		else
		{
			RA(a);
		}
		PRINT(a, b);
	}
	RRB(b);
	PRINT(a, b);
	j = *(b->n);
	printf("j : \n%i\n", j);
	while (j--)
	{
		PA(b, a);
		PRINT(a, b);
	}
	printf("i : %i\nend\n\n", i);
	return (i);
}

t_lst	*quicksort(t_lst *a, t_lst *b, int lo, int hi)
{
	int	p;
	
	if (lo < hi)
	{
		p = partition(a, b, lo, hi);
		quicksort(a, b, lo, p - 1);
		quicksort(a, b, p + 1, hi);
	}
	return (a);
}
