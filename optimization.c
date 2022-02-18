/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:40:28 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 16:56:09 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opt_rrr(t_call call, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (i < call.ra && i < call.rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < call.ra)
	{
		rra(a);
		i++;
	}
	while (i < call.rb)
	{
		rrb(b);
		i++;
	}
}

void	three_sort(t_list **a)
{
	if (lst_value(*a) < lst_value((*a)->next))
	{
		if (lst_value(*a) > lst_value((*a)->next->next))
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else
	{
		if (lst_value(*a) > lst_value((*a)->next->next))
		{
			if (lst_value((*a)->next) > lst_value((*a)->next->next))
			{
				ra(a);
				sa(a);
			}
			else
				ra(a);
		}
		else
			sa(a);
	}
}

void	five_sort(t_list **a, t_list **b)
{
	t_pair	pivot;
	int		i;

	i = 0;
	pivot = get_pivot(*a, 5);
	while (i++ < 5)
	{
		if (lst_value(*a) <= pivot.left)
			pb(a, b);
		else
			ra(a);
	}
	three_sort(a);
	if (!is_sorted(*b, 2, 0))
		sb(b);
	pa(a, b);
	pa(a, b);
}
