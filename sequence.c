/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:28:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/29 14:08:37 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*trim_sequence_small(t_stk **g_stack)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	while (++i < (*(*g_stack)->n) - 1)
	{
		tmp = (*g_stack)->next;
		if (redudancy((*g_stack)->str, tmp->str))
		{
			(*g_stack)->str = "ss";
			(*g_stack)->next = tmp->next;
			*g_stack = (*g_stack)->start;
			(*(*g_stack)->n)--;
			free(tmp);
		}
		else
			*g_stack = (*g_stack)->next;
	}
	return ((*g_stack)->start);
}

void	trim_sequence_bis(t_stk **g_stack, t_stk **tmp, int y)
{
	if (y)
	{
		*tmp = (*g_stack)->next;
		(*tmp)->next = (*g_stack)->next->next;
	}
	else
	{
		free((*tmp)->next);
		free(*tmp);
	}
}

t_stk	*trim_sequence(t_stk **g_stack)
{
	int		i;
	t_stk	*tmp;

	i = -1;
	while (++i < (*(*g_stack)->n) - 1)
	{
		trim_sequence_bis(g_stack, &tmp, 1);
		if (redudancy(tmp->str, tmp->next->str))
		{
			if (((*(*g_stack)->n) - i) > 3)
			{
				(*g_stack)->next = tmp->next->next;
				*g_stack = (*g_stack)->start;
				(*(*g_stack)->n)--;
				i = 0;
			}
			else
				(*g_stack)->next = 0;
			(*(*g_stack)->n)--;
			trim_sequence_bis(g_stack, &tmp, 0);
		}
		else
			*g_stack = (*g_stack)->next;
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
