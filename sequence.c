/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:28:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/26 20:15:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		redudancy(char *str1, char *str2)
{
	return ((ft_strequ("rrr", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("rra", str1) && ft_strequ("ra", str2))
			|| (ft_strequ("ra", str1) && ft_strequ("rra", str2)));
}

t_stk	*trim_sequence(t_stk **g_stack)
{
	int		i;
	int		n;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = 0;
	n = (*(*g_stack)->n);
	while (i < n - 1)
	{
		tmp1 = (*g_stack)->next;
		tmp2 = (*g_stack)->next->next;
		if (redudancy(tmp1->str, tmp2->str))
		{
			if ((n - i) > 3)
			{
				(*g_stack)->next = tmp2->next;
				*g_stack = (*g_stack)->start;
				n--;
				i = 0;
			}
			else
				(*g_stack)->next = 0;
			n--;
			free(tmp1);
			free(tmp2);
		}
		else
			*g_stack = (*g_stack)->next;
		i++;
	}
	return ((*g_stack)->start);
}

void	init_action_bis(t_stk **g_stack, char *str)
{
	if (!(*g_stack = (t_stk *)malloc(sizeof(t_stk))))
		return ;
	if (!((*g_stack)->n = (int *)malloc(sizeof(int))))
		return ;
	(*g_stack)->str = str;
	(*(*g_stack)->n) = 1;
	(*g_stack)->start = *g_stack;
	(*g_stack)->next = 0;
}

void	init_action(t_stk **g_stack, char *str)
{
	t_stk	*start;
	int		*len;

	if ((*g_stack))
	{
		if (!((*g_stack)->next = (t_stk *)malloc(sizeof(t_stk))))
			return ;
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
		init_action_bis(g_stack, str);
}
