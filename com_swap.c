/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:36 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 15:30:22 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	sa(t_list **a)
{
	t_list	*before;
	t_list	*top;

	if (!(*a)->next)
		return ;
	before = (*a)->next;
	top = *a;
	ft_lstdel_front(a);
	ft_lstdel_front(a);
	ft_lstadd_front(a, top);
	ft_lstadd_front(a, before);
	ft_putendl_fd("sa", 0);
}

void	sb(t_list **b)
{
	t_list	*before;
	t_list	*top;

	if (!(*b)->next)
		return ;
	before = (*b)->next;
	top = *b;
	ft_lstdel_front(b);
	ft_lstdel_front(b);
	ft_lstadd_front(b, top);
	ft_lstadd_front(b, before);
	ft_putendl_fd("sb", 0);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 0);
}
