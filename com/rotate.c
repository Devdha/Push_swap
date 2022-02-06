/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:35 by dha               #+#    #+#             */
/*   Updated: 2022/02/06 15:20:43 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	ra(t_list **a)
{
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	ft_lstdel_back(a);
	ft_lstadd_front(a, last);
}

void	rb(t_list **b)
{
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	ft_lstdel_back(b);
	ft_lstadd_front(b, last);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
