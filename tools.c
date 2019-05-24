/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:57:06 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/24 18:18:17 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	print_stk(t_stk *g_stack)
{
	while (g_stack)
	{
		printf("%s\n", g_stack->str);
		g_stack = g_stack->next;
	}
}

void	sort_int_tab(long *tab, int size)
{
	int		i;
	int		j;
	long	tmp;

	i= 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	check_lst(t_lst *a)
{
	int		i;
	int		j;
	int		k;
	int		tab[(*a->n)];

	i = 0;
	k = 0;
	while (a->next)
	{
		a->val > a->next->val ? k++ : 0;
	 	a->val < INT_MIN || a->val > INT_MAX ? kill("Error") : 0;
		tab[i++] = a->val;
		a = a->next;
	}
	tab[i] = a->val;
	i = -1;
	while (i++ < (*a->n) - 1)
	{
		j = i + 1;
		while (j <= (*a->n) - 1)
			tab[i] == tab[j++] ? kill("Error") : 0;
	}
	k == 0 ? exit(EXIT_SUCCESS) : 0;
}

void	check_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str) && !ft_issign(*str))
			kill("Error");
		str++;
	}
}
