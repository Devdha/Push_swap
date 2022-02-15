/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:40:28 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 15:06:40 by dha              ###   ########seoul.kr  */
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

void	three_sort(t_list **a, t_list **b)
{
	
}

void	five_sort(t_list **a, t_list **b)
{
	
}