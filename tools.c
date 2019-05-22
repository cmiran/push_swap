/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:57:06 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/22 18:10:04 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	PRINT STACK
int		print_stk(t_stk *g_stack)
{
	t_stk	*start;

	start = g_stack;
	while (g_stack)
	{
		printf("%s\n", g_stack->str);
		g_stack = g_stack->next;
	}
	g_stack = start;
	return (1);
}

//	PRINT LIST
int		print_lst(t_lst **alst)
{
	t_lst	*start;

	start = *alst;
	while (*alst)
	{
		printf("%li", (*alst)->val);
		*alst = (*alst)->next;
		if (*alst)
			printf("  ");
	}
	*alst = start;
	if (*alst)
		printf("\nlen : %i\n", (*(*alst)->n));
	return (1);
}

void	sort_int_tab(long *tab, int size)
{
	int	i;
	int	j;
	long	tmp;

	i= 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

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

void	insertionsort(t_lst **a, t_lst **b, int lo, int hi)
{
	int		i;

	i = lo;
	hi == (*(*a)->n) ? i++ : 0;
	while (i < hi)
	{
		while (i >= lo && swap_me(a, 0))
		{
			RRA(a);
			i--;
		}
		RA(a);
		i++;
	}
	if (hi == (*(*a)->n))
	{
		RA(a);
	}
}
