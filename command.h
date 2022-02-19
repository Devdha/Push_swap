/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:55:08 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:44:48 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "push_swap.h"

void	pa(t_list **a, t_list **b, int is_checker);
void	pb(t_list **a, t_list **b, int is_checker);
void	sa(t_list **a, int is_checker);
void	sb(t_list **b, int is_checker);
void	ss(t_list **a, t_list **b, int is_checker);
int		ra(t_list **a, int is_checker);
int		rb(t_list **b, int is_checker);
void	rr(t_list **a, t_list **b, int is_checker);
void	rra(t_list **a, int is_checker);
void	rrb(t_list **b, int is_checker);
void	rrr(t_list **a, t_list **b, int is_checker);

#endif
