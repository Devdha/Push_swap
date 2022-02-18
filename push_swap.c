/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:41:46 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 23:52:05 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a_to_b_2(int size, t_list **a, t_list **b, t_call *call)
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
			if (lst_value(*b) < pivot.left)
				call->rb += rb(b);
		}
	}
}

void	init_a_to_b(int size, t_list **a, t_list **b)
{
	t_call	call;

	call = init_call();
	init_a_to_b_2(size, a, b, &call);
	a_to_b(call.ra, a, b);
	b_to_a(call.pb - call.rb, a, b);
	b_to_a(call.rb, a, b);
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
		init_a_to_b(ft_lstsize(*a), a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	a = input(argc, argv);
	if (is_sorted(a, 0, 1))
		exit(EXIT_SUCCESS);
	push_swap(&a, &b);
	exit(EXIT_SUCCESS);
}
