/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:36 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:34:27 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	sa(t_list **a, int is_checker)
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
	if (!is_checker)
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **b, int is_checker)
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
	if (!is_checker)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **a, t_list **b, int is_checker)
{
	t_list	*before;
	t_list	*top;

	if ((*a)->next)
	{
		before = (*a)->next;
		top = *a;
		ft_lstdel_front(a);
		ft_lstdel_front(a);
		ft_lstadd_front(a, top);
		ft_lstadd_front(a, before);
	}
	if ((*b)->next)
	{
		before = (*b)->next;
		top = *b;
		ft_lstdel_front(b);
		ft_lstdel_front(b);
		ft_lstadd_front(b, top);
		ft_lstadd_front(b, before);
	}
	if (!is_checker)
		ft_putendl_fd("ss", 1);
}
