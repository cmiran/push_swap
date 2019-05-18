/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:35:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/18 15:02:37 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*init_node(int *n)
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

intmax_t	ps_atoi(char *str, int *index)
{
	intmax_t	nbr;
	int			sign;

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

t_lst		*parse(int ac, char **av, t_lst *start)
{
	t_lst		*node;
	int			i;
	int			j;

	node = start;
	i = 0;
	while (++i < ac)
	{
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

// PRINT
int	print(t_lst **alst)
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

int			main(int ac, char **av)
{
	t_var	var;
	t_lst	*tmp;

	var.a = NULL;
	var.b = NULL;
	var.a = init_node(0);
	if (ac > 1)
	{
		if (!(var.a = parse(ac, av, var.a)))
			return (0);
		var.a = quicksort(&var.a, &var.b, 0, *(var.a->n));
	}
// 	PRINT(&var.a, 0);	
// FREE
	free(var.a->n);
	while (var.a)
	{
		tmp = var.a->next;
		var.a->val = 0;
		var.a->next = NULL;
		free(var.a);
		var.a = tmp;
	}
/*	free(var.a->n);
	while (var.b)
	{
		tmp = var.b->next;
		var.b->val = 0;
		var.b->next = NULL;
		free(var.b);
		var.b = tmp;
	}*/
	return (0);
}
