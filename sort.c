/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:39:00 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 15:58:04 by dha              ###   ########seoul.kr  */
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
			call->rb += rb(b);
		else
		{
			pa(a, b);
			call->pa++;
			if (lst_value(*a) < pivot.right)
				call->ra += ra(a);
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
			call->ra += ra(a);
		else
		{
			pb(a, b);
			call->pb++;
			if (lst_value(*b) >= pivot.left)
				call->rb += rb(b);
		}
	}
}

void	b_to_a(int size, t_list **a, t_list **b)
{
	t_call	call;

	if (size < 3)
	{
		if (size == 2 && !is_sorted(*b, 2, 0))
			sb(b);
		while (size--)
			pa(a, b);
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

	if (size < 3)
	{
		if (size == 2 && !is_sorted(*a, 2, 1))
			sa(a);
		return ;
	}
	call = init_call();
	a_to_b_2(size, a, b, &call);
	opt_rrr(call, a, b);
	a_to_b(call.ra, a, b);
	b_to_a(call.rb, a, b);
	b_to_a(call.pb - call.rb, a, b);
}

void	push_swap(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 3)
		three_sort(a);
	else if (size == 5)
		five_sort(a, b);
	else
		a_to_b(ft_lstsize(*a), a, b);
}
