/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:36 by dha               #+#    #+#             */
/*   Updated: 2022/02/08 15:37:39 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	sa(t_list **a)
{
	t_list	*before;
	t_list	*last;

	if (!(*a)->next)
		return ;
	before = ft_lst_beforelast(*a);
	last = ft_lstlast(*a);
	ft_lstdel_back(a);
	ft_lstdel_back(a);
	ft_lstadd_back(a, last);
	ft_lstadd_back(a, before);
}

void	sb(t_list **b)
{
	t_list	*before;
	t_list	*last;

	if (!(*b)->next)
		return ;
	before = ft_lst_beforelast(*b);
	last = ft_lstlast(*b);
	ft_lstdel_back(b);
	ft_lstdel_back(b);
	ft_lstadd_back(b, last);
	ft_lstadd_back(b, before);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
