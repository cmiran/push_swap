/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:13:20 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/09 13:25:18 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_lst **start)
{
	intmax_t	tmp;
	
	tmp = (*start)->val;
	(*start)->val = (*start)->next->val;
	(*start)->next->val = tmp;
}

void	ss(t_lst **a, t_lst **b)
{
	s(a);
	s(b);
}
