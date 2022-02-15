/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:33 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 15:10:22 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	rra(t_list **a)
{
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	ft_lstdel_back(a);
	ft_lstadd_front(a, last);
	ft_putendl_fd("rra", 0);
}

void	rrb(t_list **b)
{
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	ft_lstdel_back(b);
	ft_lstadd_front(b, last);
	ft_putendl_fd("rrb", 0);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_putendl_fd("rrr", 0);
}
