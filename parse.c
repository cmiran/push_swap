/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:40:50 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/26 17:25:58 by cmiran           ###   ########.fr       */
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

void	check_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str) && !ft_issign(*str))
			kill("\033[1;31mError\033[0m", 1);
		str++;
	}
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
