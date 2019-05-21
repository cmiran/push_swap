/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:28:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/21 00:18:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	redudancy(char *str1, char *str2)
{
	return ((ft_strequ("rrr", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("rra", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("ra", str1) && ft_strequ("rra", str2)));
}

t_stack	*trim_sequence(t_stack **g_stack)
{
	int	n;
	t_stack	*tmp1;
	t_stack *tmp2;

	n = (*(*g_stack)->n);
	while (n-- > 2)
	{
		tmp1 = (*g_stack)->next;
		tmp2 = (*g_stack)->next->next;
		if (redudancy(tmp1->str, tmp2->str))
		{
			if (n > 3)
			{
				(*g_stack)->next = tmp2->next;
				*g_stack = (*g_stack)->next;
				n--;
			}
			else
				(*g_stack)->next = 0;
			n--;
			free(tmp1);
			free(tmp2);
		}
		else
			*g_stack = (*g_stack)->next;
	}
	return ((*g_stack)->start);
}

t_stack	*init_action(t_stack **g_stack, char *str)
{
	t_stack	*start;
	int	*len;

	if ((*g_stack))
	{
		if (!((*g_stack)->next = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		(*(*g_stack)->n)++;
		start = (*g_stack)->start;
		len = (*g_stack)->n;
		*g_stack = (*g_stack)->next;
		(*g_stack)->str = str;
		(*g_stack)->n = len;
		(*g_stack)->start = start;
		(*g_stack)->next = 0;
	}
	else
	{
		if (!(*g_stack = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		if (!((*g_stack)->n = (int *)malloc(sizeof(int))))
			return (0);
		(*g_stack)->str = str;
		(*(*g_stack)->n) = 1;
		(*g_stack)->start = *g_stack;
		(*g_stack)->next = 0;
	}
	return (*g_stack);
}
