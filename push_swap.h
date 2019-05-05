/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:05:45 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/05 19:44:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int		val;
	t_list	*next;
}	t_list;

typedef struct	s_variables
{
	t_list	*a;
	t_list	*b;
}	t_var;

#endif
