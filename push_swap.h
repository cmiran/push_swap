/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/10 19:05:19 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct	s_node
{
	intmax_t	val;
//	int		len;
	struct s_node	*next;
//	struct s_node	*start;
}		t_lst;

typedef struct	s_variables
{
	t_lst	*a;
	t_lst	*b;
	intmax_t	pivot;
}		t_var;

int		main(int ac, char **av);
/*
** t_lst	*parse(int ac, char **av, t_lst *start)
** intmax_t	ps_atoi(char *str, int *index)
*/
t_lst		*init_node(void);

void	s(t_lst **start);
void	ss(t_lst **a, t_lst **b);
void	p(t_lst **lst1, t_lst **lst2);
void	r(t_lst **alst);
void	rr(t_lst **a, t_lst **b);
void	rv(t_lst **alst);
void	rrr(t_lst **a, t_lst **b);

#endif
