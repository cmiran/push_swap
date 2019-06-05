/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:57:06 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/06 00:12:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_lst *a, t_lst *b, char *line)
{
	t_lst	*tmp1;
	t_stk	*tmp2;

	a ? free(a->n) : 0;
	while (a)
	{
		tmp1 = a->next;
		free(a);
		a = tmp1;
	}
	b ? free(b->n) : 0;
	while (b)
	{
		tmp1 = b->next;
		free(a);
		b = tmp1;
	}
	g_stack ? free(g_stack->n) : 0;
	while (g_stack)
	{
		tmp2 = g_stack->next;
		free(g_stack);
		g_stack = tmp2;
	}
	line ? free(line) : 0;
}

void	kill(char *str, int m, t_lst *a, t_lst *b)
{
	a || b ? free_all(a, b, 0) : 0;
	ft_putendl(str);
	m ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}

void	sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
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

void	check_lst(t_lst *a, int n)
{
	int		i;
	int		j;
	int		tab[n];

	i = 0;
	while (a)
	{
		a->val < INT_MIN || a->val > INT_MAX ?\
			kill("\033[1;31mError\033[0m", 1, a, 0) : 0;
		tab[i] = a->val;
		a = a->next;
		i++;
	}
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			tab[i] == tab[j] ?\
					kill("\033[1;31mError\033[0m", 1, a, 0) : 0;
			j++;
		}
		i++;
	}
}

int		is_sorted(t_lst *a, t_lst *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}
