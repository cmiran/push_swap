/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:35:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/08 20:25:08 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*init_node(void)
{
	t_lst *node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	node->val = 0;
	node->next = 0;
	return (node);
}

intmax_t	ps_atoi(char *str, int *index)
{
	intmax_t	nbr;
	char		sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(str[*index]))
		(*index)++;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (*str == '-')
			sign *= -1;
		(*index)++;;
	}
	while (ft_isdigit(str[*index]))
	{
		nbr = nbr * 10 + *str - '0';
		(*index)++;
	}
	return (nbr * sign);
}

t_lst		*parse(int ac, char **av, t_lst *start)
{
	t_lst	*node;
	int		i;
	int		j;
	char	*str;

	node = start;
	i = 1;
	while (i < ac)
	{
		str = av[i];
		j = 0;
		while (str[j])
		{
			if (!(node->val = ps_atoi(str, &j)))
				return (0);
			else
			{
				if (!(node->next = init_node()))
					return (0);
				node = node->next;
			}
		}
		i++;
	}
	return (start);
}

int			main(int ac, char **av)
{
	t_var	var;
	t_lst	*lst;
	t_lst 	*tmp;

	if (!(var.a = init_node()))
		return (0);
	if (ac > 1)
	{
		if (!(var.a = parse(ac, av, var.a)))
			return (0);
	}
	lst = var.a;
	while (lst)
	{
		printf("%li\n", lst->val);
		lst = lst->next;
	}
	while (var.a)
	{
		tmp = var.a->next;
		var.a->val = 0;
		var.a->next = 0;
		free(var.a);
		var.a = tmp;
	}
	return (0);
}
