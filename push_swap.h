/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:39:17 by dha               #+#    #+#             */
/*   Updated: 2022/02/13 15:14:59 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "command.h"
# include <stdio.h>

typedef struct s_pair
{
	int	left;
	int	right;
}				t_pair;

typedef struct s_call
{
	int pa;
	int pb;
	int ra;
	int rb;
	int rra;
	int rrb;
}				t_call;

t_list	*input(int argc, char **argv);
int		is_sorted(t_list *lst);
int		lst_value(t_list *lst);
int		lst_max(t_list *lst);
t_pair	get_pivot(t_list *lst, int size);
t_call	init_call(void);
void	push_swap(t_list **a, t_list **b);
void	a_to_b(int size, t_list **a, t_list **b);
void	b_to_a(int size, t_list **a, t_list **b);

#endif