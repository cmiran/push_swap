/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:04:35 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/06 15:41:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		instruction(t_lst **a, t_lst **b, char *line)
{
	if (ft_strequ(line, "sa"))
		s(a);
	else if (ft_strequ(line, "sb"))
		s(b);
	else if (ft_strequ(line, "ss"))
		ss(a, b);
	else if (ft_strequ(line, "pa"))
		p(b, a);
	else if (ft_strequ(line, "pb"))
		p(a, b);
	else if (ft_strequ(line, "ra"))
		r(a);
	else if (ft_strequ(line, "rb"))
		r(b);
	else if (ft_strequ(line, "rr"))
		rr(a, b);
	else if (ft_strequ(line, "rra"))
		rv(a);
	else if (ft_strequ(line, "rrb"))
		rv(b);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	char	*line;

	if (ac > 1)
	{
		a = init_node(0);
		b = NULL;
		if (!(a = parse(ac, av, a)))
			kill("\033[1;31mError\033[0m", 1, a, 0);
		check_lst(a, *(a->n));
		while (get_next_line(0, &line) > 0)
		{
			if (!instruction(&a, &b, line))
			{
				free_all(a, b, line);
				kill("\033[1;31mError\033[0m", 1, 0, 0);
			}
			free(line);
		}
		is_sorted(a, b) ? kill("\033[1;32mOK\033[0m", 0, a, b) :\
			kill("\033[1;31mKO\033[0m", 1, a, b);
	}
	return (0);
}
