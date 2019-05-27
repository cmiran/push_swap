/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:43:48 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/27 00:21:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stk(t_stk *g_stack)
{
	while (g_stack)
	{
		printf("%s\n", g_stack->str);
		g_stack = g_stack->next;
	}
}

int		main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac > 1)
	{
		a = init_node(0);
		b = NULL;
		if (!(a = parse(ac, av, a)))
			return (0);
		check_lst(a);
		if (is_sorted(a, 0))
			exit(EXIT_SUCCESS);
		*(a->n) > 7 ? quicksort(&a, &b, 0, *(a->n)) :\
			insertionsort(&a, 1, *(a->n));
		g_stack = trim_sequence(&g_stack->start);
		print_stk(g_stack->start);
		free_all(a, b, 0);
	}
	return (0);
}
