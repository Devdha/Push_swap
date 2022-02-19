/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:39:00 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:37:54 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_2(int size, t_list **a, t_list **b, t_call *call)
{
	t_pair	pivot;
	int		i;

	i = 0;
	pivot = get_pivot(*b, size);
	while (i++ < size)
	{
		if (lst_value(*b) < pivot.left)
			call->rb += rb(b, 0);
		else
		{
			pa(a, b, 0);
			call->pa++;
			if (lst_value(*a) < pivot.right)
				call->ra += ra(a, 0);
		}
	}
}

void	a_to_b_2(int size, t_list **a, t_list **b, t_call *call)
{
	t_pair	pivot;
	int		i;

	i = 0;
	pivot = get_pivot(*a, size);
	while (i++ < size)
	{
		if (lst_value(*a) >= pivot.right)
			call->ra += ra(a, 0);
		else
		{
			pb(a, b, 0);
			call->pb++;
			if (lst_value(*b) >= pivot.left)
				call->rb += rb(b, 0);
		}
	}
}

void	b_to_a(int size, t_list **a, t_list **b)
{
	t_call	call;

	if (is_sorted(*b, size, 0) || size < 3)
	{
		if (size == 2 && !is_sorted(*b, 2, 0))
			sb(b, 0);
		while (size--)
			pa(a, b, 0);
		return ;
	}
	call = init_call();
	b_to_a_2(size, a, b, &call);
	a_to_b(call.pa - call.ra, a, b);
	opt_rrr(call, a, b);
	a_to_b(call.ra, a, b);
	b_to_a(call.rb, a, b);
}

void	a_to_b(int size, t_list **a, t_list **b)
{
	t_call	call;

	if (is_sorted(*a, size, 1) || size < 3)
	{
		if (size == 2 && !is_sorted(*a, 2, 1))
			sa(a, 0);
		return ;
	}
	call = init_call();
	a_to_b_2(size, a, b, &call);
	opt_rrr(call, a, b);
	a_to_b(call.ra, a, b);
	b_to_a(call.rb, a, b);
	b_to_a(call.pb - call.rb, a, b);
}
