/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:16:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/11 19:16:02 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_lst **alst)
{
	t_lst		*start;
	t_lst		*tmp;

	if (!(*alst)->next)
		return ;
	start = (*alst)->next;
	tmp = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = init_node(tmp->n);
	(*alst)->next->val = tmp->val;
	free(tmp);
	*alst = start;
}

void	rr(t_lst **a, t_lst **b)
{
	r(a);
	r(b);
}

void	rv(t_lst **alst)
{
	t_lst		*start;

	if (!(*alst)->next)
		return ;
	start = init_node((*alst)->n);
	start->next = *alst;
	while ((*alst)->next->next)
		*alst = (*alst)->next;
	start->val = (*alst)->next->val;
	free((*alst)->next);
	(*alst)->next = 0;
	*alst = start;
}

void	rrr(t_lst **a, t_lst **b)
{
	rv(a);
	rv(b);
}
