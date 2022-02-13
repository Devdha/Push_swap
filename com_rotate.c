/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:35 by dha               #+#    #+#             */
/*   Updated: 2022/02/13 15:26:26 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	ra(t_list **a)
{
	t_list	*first;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	ft_lstdel_front(a);
	ft_lstadd_back(a, first);
}

void	rb(t_list **b)
{
	t_list	*first;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	ft_lstdel_front(b);
	ft_lstadd_back(b, first);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
