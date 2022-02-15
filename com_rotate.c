/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:35 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 15:31:57 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	ra(t_list **a)
{
	t_list	*first;

	if (!*a || !(*a)->next)
		return (0);
	first = *a;
	ft_lstdel_front(a);
	ft_lstadd_back(a, first);
	ft_putendl_fd("ra", 0);
	return (1);
}

int	rb(t_list **b)
{
	t_list	*first;

	if (!*b || !(*b)->next)
		return (0);
	first = *b;
	ft_lstdel_front(b);
	ft_lstadd_back(b, first);
	ft_putendl_fd("rb", 0);
	return (1);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_putendl_fd("rr", 0);
}
