/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/29 17:20:00 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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
	long			val;
	int				*n;
	struct s_node	*next;
}				t_lst;

typedef struct	s_action
{
	char			*str;
	int				*n;
	struct s_action	*start;
	struct s_action	*next;
}				t_stk;

t_stk		*g_stack;

/*
**	push_swap.c
*/
int				main(int ac, char **av);
int				redudancy(char *str1, char *str2);
/*
**	void	print_stk(t_stk *g_stack)
*/

/*
**	checker.c
*/
int				main(int ac, char **av);
/*
**	int		instruction(t_lst **a, t_lst **b, char *line)
*/

/*
**	parse.c
*/
t_lst			*parse(int ac, char **av, t_lst *start);
t_lst			*init_node(int *n);
/*
** void		check_str(char *str)
** long		ps_atoi(char *str, int *index)
*/

/*
**	quicksort.c
*/
void			quicksort(t_lst **a, t_lst **b, int lo, int hi);
int				find_median(t_lst **a, int lo, int hi);
/*
** int		partition(t_lst **a, t_lst **b, int lo, int hi)
** void		rotate_back(t_lst **a, t_lst **b, int n)
** void		push_back(t_lst **a, t_lst **b, int n)
*/

/*
**	insertionsort.c
*/
void			insertionsort(t_lst **a, int lo, int hi);
void			lowsort(t_lst **a, t_lst **b, int lo, int hi);
/*
** void		small_partition(t_lst **a, t_lst **b, int lo, int hi)
** int		swap_me(t_lst **a, t_lst **b)
** int		is_reverse_sorted(t_lst *b)
*/

/*
**	sequence.c
*/
void			init_action(t_stk **g_stack, char *str);
t_stk			*trim_sequence(t_stk **g_stack);
t_stk			*trim_sequence_small(t_stk **g_stack);
/*
** void		init_action_bis(t_stk **g_stack, char *str)
*/

/*
**	tools.c
*/

int				is_sorted(t_lst *a, t_lst *b);
void			check_lst(t_lst *a, int n);
void			sort_int_tab(int *tab, int size);
void			kill(char *str, int m);
void			free_all(t_lst *a, t_lst *b, char *line);

/*
**	swap.c
*/
void			s(t_lst **start);
void			ss(t_lst **a, t_lst **b);

/*
**	push.c
*/
void			p(t_lst **lst1, t_lst **lst2);
/*
**	void	p_bis(t_lst **lst1, t_lst **lst2)
*/

/*
**	rotate.c
*/
void			r(t_lst **alst);
void			rr(t_lst **a, t_lst **b);
void			rv(t_lst **alst);
void			rrr(t_lst **a, t_lst **b);

int				print_lst(t_lst **alst);
void			print_stk(t_stk *g_stack);

#endif
