/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:39:00 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 21:29:40 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lst(int pivot, int size, t_list *lst, int ascending)
{
	while (lst && size--)
	{
		if (ascending && lst_value(lst) < pivot)
			return (0);
		else if (!ascending && lst_value(lst) >= pivot)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	b_to_a_2(int size, t_list **a, t_list **b, t_call *call)
{
	t_pair	pivot;
	int		i;

	i = 0;
	pivot = get_pivot(*b, size);
	while (i++ < size)
	{
		if (call->pa > size * 2 / 3 && \
			check_lst(pivot.left, size - call->pb, *a, 0))
			break ;
		if (lst_value(*b) < pivot.left)
			call->rb += rb(b);
		else
		{
			pa(a, b);
			call->pa++;
			if (lst_value(*a) < pivot.right)
			{
				if (lst_value(*b) < pivot.left && i + 2 < size)
				{
					call->rr += rr(a, b);
					i++;
				}
				else
					call->ra += ra(a);
			}
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
		if (call->pb > size * 2 / 3 && \
			check_lst(pivot.right, size - call->pb, *a, 1))
			break ;
		if (lst_value(*a) >= pivot.right)
			call->ra += ra(a);
		else
		{
			pb(a, b);
			call->pb++;
			if (lst_value(*b) >= pivot.left)
			{
				if (lst_value(*a) >= pivot.right && i + 2 < size)
				{
					call->rr += rr(a, b);
					i++;
				}
				else
					call->rb += rb(b);
			}
		}
	}
}

void	b_to_a(int size, t_list **a, t_list **b)
{
	t_call	call;

	if (is_sorted(*b, size, 0) || size < 3)
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

	if (is_sorted(*a, size, 1) || size < 3)
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
