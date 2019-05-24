/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:35:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/24 18:18:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*init_node(int *n)
{
	t_lst *node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	node->val = 0;
	node->next = 0;
	if (!n)
	{
		if (!(node->n = (int *)malloc(sizeof(int))))
			return (0);
		(*node->n) = 1;
	}
	else
		node->n = n;
	return (node);
}

long	ps_atoi(char *str, int *index)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(str[*index]))
		(*index)++;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (*str == '-')
			sign *= -1;
		(*index)++;
	}
	while (ft_isdigit(str[*index]))
	{
		nbr = nbr * 10 + str[*index] - '0';
		(*index)++;
	}
	return (nbr * sign);
}

t_lst	*parse(int ac, char **av, t_lst *start)
{
	t_lst		*node;
	int			i;
	int			j;

	node = start;
	i = 0;
	while (++i < ac)
	{
		check_str(av[i]);
		j = 0;
		while (av[i][j])
		{
			node->val = ps_atoi(av[i], &j);
			if (av[i][j] || i + 1 < ac)
			{
				node->next = init_node(start->n);
				node = node->next;
				(*node->n)++;
			}
		}
	}
	return (start);
}

int		main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*tmp1;
	t_stk	*tmp2;

	a = NULL;
	b = NULL;
	g_stack = NULL;
	a = init_node(0);
	if (ac > 1)
	{
		if (!(a = parse(ac, av, a)))
			return (0);
		check_lst(a);
		*(a->n) > 7 ? quicksort(&a, &b, 0, *(a->n)) :\
			insertionsort(&a, &b, 1, *(a->n));
		g_stack = trim_sequence(&g_stack->start);
		print_stk(g_stack->start);
	}
	free(a->n);
	while (a)
	{
		tmp1 = a->next;
		a->val = 0;
		a->next = 0;
		free(a);
		a = tmp1;
	}
	free(g_stack->n);
	while (g_stack)
	{
		tmp2 = g_stack->next;
		g_stack->str = NULL;
		g_stack->next = 0;
		free(g_stack);
		g_stack = tmp2;
	}
	return (0);
}
