/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/08 19:24:42 by cmiran           ###   ########.fr       */
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
	intmax_t		val;
	struct s_node	*next;
}	t_lst;

typedef struct	s_variables
{
	t_lst	*a;
	t_lst	*b;
}	t_var;

#endif
