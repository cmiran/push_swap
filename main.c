/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:35:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/10 19:05:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PRINT
void	print(t_lst **alst)
{
	t_lst	*start;

	start = *alst;
	while (*alst)
	{
		printf("%li\n", (*alst)->val);
		*alst = (*alst)->next;
	}
	*alst = start;
}

t_lst		*init_node(void)
{
	t_lst *node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	node->val = 0;
	node->next = 0;
/*	if (!(*alst)->start)
	{
		node->len = 1;
		node->start = node;
	}
	else
	{
		(*alst)->len++;
		node->len = (*alst)->len;
		node->start = (*alst)->start;
	}*/
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
				node->next = init_node();
				node = node->next;
			}
		}
	}
	return (start);
}

int			main(int ac, char **av)
{
	t_var	var;
	t_lst	*tmp;

	var.a = init_node();
	if (ac > 1)
	{
		if (!(var.a = parse(ac, av, var.a)))
			return (0);
	}

	var.b = NULL;
// TEST
	s(&var.a);
	rv(&var.a);
	r(&var.a);
	s(&var.a);
	rv(&var.a);
	p(&var.a, &var.b);
	p(&var.a, &var.b);
	p(&var.a, &var.b);
	rr(&var.a, &var.b);
	rr(&var.a, &var.b);
	rrr(&var.a, &var.b);
	rrr(&var.a, &var.b);
	ss(&var.a, &var.b);
	p(&var.b, &var.a);
	p(&var.b, &var.a);
	p(&var.b, &var.a);

// PRINT
	print(&var.a);
	if (var.b)
		printf("\n");
	print(&var.b);

// FREE
	while (var.a)
	{
		tmp = var.a->next;
		var.a->val = 0;
		var.a->next = NULL;
		free(var.a);
		var.a = tmp;
	}
	while (var.b)
	{
		tmp = var.b->next;
		var.b->val = 0;
		var.b->next = NULL;
		free(var.b);
		var.b = tmp;
	}

	return (0);
}
