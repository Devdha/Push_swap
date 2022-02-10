/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:35 by dha               #+#    #+#             */
/*   Updated: 2022/02/10 21:01:35 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	ra(t_list **a)
{
	t_list	*first;

	if (!*a || !(*a)->next)
		return ;
	first = ft_lstlast(*a);
	ft_lstdel_front(a);
	ft_lstadd_back(a, first);
}

void	rb(t_list **b)
{
	t_list	*first;

	if (!*b || !(*b)->next)
		return ;
	first = ft_lstlast(*b);
	ft_lstdel_front(b);
	ft_lstadd_back(b, first);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
