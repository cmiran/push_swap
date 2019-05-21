/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/20 22:35:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# define PRINT(a, b)	printf("A\n"); print_lst(a);\
	b ? printf("\nB\n") && print_lst(b) && printf("\n") : 0;

# define SA(a)		init_action(&g_stack, "sa"); s(a);
# define SB(b)		init_action(&g_stack, "sb"); s(b);
# define SS(a, b)	init_action(&g_stack, "ss"); ss(a, b);
# define PA(b, a)	init_action(&g_stack, "pa"); p(b, a);
# define PB(a, b)	init_action(&g_stack, "pb"); p(a, b);
# define RA(a)		init_action(&g_stack, "ra"); r(a);
# define RB(b)		init_action(&g_stack, "rb"); r(b);
# define RR(a, b)	init_action(&g_stack, "rr"); rr(a, b);
# define RRA(a)		init_action(&g_stack, "rra"); rv(a);
# define RRB(b)		init_action(&g_stack, "rrb"); rv(b);
# define RRR(a, b)	init_action(&g_stack, "rrr"); rrr(a, b);

typedef struct	s_node
{
	long		val;
	int		*n;
	struct s_node	*next;
}		t_lst;

typedef struct	s_action
{
	char		*str;
	int		*n;
	struct s_action	*start;
	struct s_action	*next;
}	t_stack;

t_stack		*g_stack;

/*
**	main.c
*/
int		main(int ac, char **av);
t_lst		*init_node(int *n);
/*
** t_lst	*parse(int ac, char **av, t_lst *start)
** long		ps_atoi(char *str, int *index)
*/

/*
**	quicksort.c
*/
void		quicksort(t_lst **a, t_lst **b, int lo, int hi);
/*
** int		partition(t_lst **a, t_lst **b, int lo, int hi)
** void		rotate_back(t_lst **a, t_lst **b, int n)
** void		push_back(t_lst **a, t_lst **b, int n)
*/

/*
**	tools.c
*/
void		insertionsort(t_lst **a, int lo, int hi);
int		swap_me(t_lst **a, t_lst **b);
void		sort_int_tab(long *tab, int size);

/*
**	sequence.c
*/
t_stack		*init_action(t_stack **g_stack, char *str);
t_stack		*trim_sequence(t_stack **g_stack);

/*
**	swap.c
*/
void		s(t_lst **start);
void		ss(t_lst **a, t_lst **b);

/*
**	push.c
*/
void		p(t_lst **lst1, t_lst **lst2);

/*
**	rotate.c
*/
void		r(t_lst **alst);
void		rr(t_lst **a, t_lst **b);
void		rv(t_lst **alst);
void		rrr(t_lst **a, t_lst **b);

int	print_lst(t_lst **alst);
int	print_stack(t_stack *g_stack);

#endif
