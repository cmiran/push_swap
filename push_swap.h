/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/15 14:57:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# define PRINT(a, b)	printf("A\n"); print(a);\
	b ? printf("\nB\n") && print(b) && printf("\n") : 0;

# define SA(alst)	write(1, "sa\n\n", 3); s(alst);
# define SB(alst)	write(1, "sb\n\n", 3); s(alst);
# define SS(a, b)	write(1, "ss\n\n", 3); ss(a, b);
# define PA(b, a)	write(1, "pa\n\n", 3); p(b, a);
# define PB(a, b)	write(1, "pb\n\n", 3); p(a, b);
# define RA(alst)	write(1, "ra\n\n", 3); r(alst);
# define RB(alst)	write(1, "rb\n\n", 3); r(alst);
# define RR(a, b)	write(1, "ss\n\n", 3); rr(a, b);
# define RRA(alst)	write(1, "rra\n\n", 4); rv(alst);
# define RRB(alst)	write(1, "rrb\n\n", 4); rv(alst);
# define RRR(a, b)	write(1, "rrr\n\n", 4); rrr(a, b);

typedef struct	s_node
{
	intmax_t	val;
	int		*n;
	struct s_node	*next;
}		t_lst;

typedef struct	s_variables
{
	t_lst	*a;
	t_lst	*b;
	intmax_t	pivot;
}		t_var;

int		main(int ac, char **av);
t_lst		*init_node(int *n);
/*
** t_lst	*parse(int ac, char **av, t_lst *start)
** intmax_t	ps_atoi(char *str, int *index)
*/
int	print(t_lst **alst);

t_lst		*quicksort(t_lst **a, t_lst **b, int lo, int hi);
/*
**
*/

void	s(t_lst **start);
void	ss(t_lst **a, t_lst **b);
void	p(t_lst **lst1, t_lst **lst2);
void	r(t_lst **alst);
void	rr(t_lst **a, t_lst **b);
void	rv(t_lst **alst);
void	rrr(t_lst **a, t_lst **b);

#endif
