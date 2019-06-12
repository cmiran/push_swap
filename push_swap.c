/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:43:48 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/12 10:52:05 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		redudancy(char *str1, char *str2)
{
	return ((ft_strequ("rrr", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("rra", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("ra", str1) && ft_strequ("rra", str2))
			|| (ft_strequ("sa", str1) && ft_strequ("sb", str2)));
}

void	print_stk(t_stk *g_stack)
{
	while (g_stack)
	{
		ft_putendl(g_stack->str);
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
		check_lst(a, *(a->n));
		if (is_sorted(a, 0))
		{
			free_all(a, 0, 0);
			exit(EXIT_SUCCESS);
		}
		*(a->n) > 5 ? quicksort(&a, &b, 0, *(a->n)) :\
			lowsort(&a, &b, 0, *(a->n));
		*(a->n) > 5 ? g_stack = trim_sequence(&g_stack->start) :\
							(g_stack = trim_sequence_small(&g_stack->start));
		print_stk(g_stack->start);
		free_all(a, b, 0);
	}
	return (0);
}
