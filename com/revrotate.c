/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:33 by dha               #+#    #+#             */
/*   Updated: 2022/02/06 15:38:07 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	rra(t_list **a)
{
	t_list	*first;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	ft_lstdel_front(a);
	ft_lstadd_back(a, first);
}

void	rrb(t_list **b)
{
	t_list	*first;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	ft_lstdel_front(b);
	ft_lstadd_back(b, first);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
