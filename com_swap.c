/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:36 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 23:11:40 by dha              ###   ########seoul.kr  */
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
	ft_putendl_fd("sa", 1);
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
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **a, t_list **b)
{
	t_list	*before;
	t_list	*top;

	if (!(*a)->next)
		return (sb(b));
	if (!(*b)->next)
		return (sa(a));
	before = (*a)->next;
	top = *a;
	ft_lstdel_front(a);
	ft_lstdel_front(a);
	ft_lstadd_front(a, top);
	ft_lstadd_front(a, before);
	before = (*b)->next;
	top = *b;
	ft_lstdel_front(b);
	ft_lstdel_front(b);
	ft_lstadd_front(b, top);
	ft_lstadd_front(b, before);
	ft_putendl_fd("ss", 1);
}
