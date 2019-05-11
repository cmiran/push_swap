/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:16:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/11 09:13:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_lst **alst)
{
	t_lst		*start;
	t_lst		*tmp;

	start = (*alst)->next;
	tmp = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = init_node(start->n);
	(*alst)->next->val = tmp->val;
	(*alst)->next->n = tmp->n;
//	free(tmp->len);
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
