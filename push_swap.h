/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/20 14:10:20 by cmiran           ###   ########.fr       */
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

# define SA(a)		write(1, "sa\n", 3); s(a);
# define SB(b)		write(1, "sb\n", 3); s(b);
# define SS(a, b)	write(1, "ss\n", 3); ss(a, b);
# define PA(b, a)	write(1, "pa\n", 3); p(b, a);
# define PB(a, b)	write(1, "pb\n", 3); p(a, b);
# define RA(a)		write(1, "ra\n", 3); r(a);
# define RB(b)		write(1, "rb\n", 3); r(b);
# define RR(a, b)	write(1, "ss\n", 3); rr(a, b);
# define RRA(a)		write(1, "rra\n", 4); rv(a);
# define RRB(b)		write(1, "rrb\n", 4); rv(b);
# define RRR(a, b)	write(1, "rrr\n", 4); rrr(a, b);

typedef struct	s_node
{
	long		val;
	int		*n;
	struct s_node	*next;
}		t_lst;

typedef struct	s_action
{
	char		*str;
	struct s_action	*start;
	struct s_action	*next;
}	t_stack;

t_stack		*g_stack->next);

/*
**	main.c
*/
int		main(int ac, char **av);
t_lst		*init_node(int *n);
/*
** t_lst	*parse(int ac, char **av, t_lst *start)
** long		ps_atoi(char *str, int *index)
*/
int	print(t_lst **alst);

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

#endif
