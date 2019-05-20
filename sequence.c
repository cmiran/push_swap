/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:28:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/20 14:10:05 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_action(t_stack **g_stack, char *str)
{
	t_stack	*start;

	if (g_stack)
	{
		if (!((*g_stack)->next = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		start = (*g_stack)->start;
		*g_stack = (*g_stack)->next;
		(*g_stack)->str = str;
		(*g_stack)->start = start;
		(*g_stack)->next = 0;
	}
	else
	{
		if (!(*g_stack = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		if (!((*g_stack)->start = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		(*g_stack)->str = str;
		(*g_stack)->start = *g_stack;
		(*g_stack)->next = 0;
	}
	return (*g_stack);
}
