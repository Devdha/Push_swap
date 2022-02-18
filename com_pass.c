/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:31 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 23:13:31 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*front;

	if (!*b)
		return ;
	front = *b;
	ft_lstdel_front(b);
	ft_lstadd_front(a, front);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*front;

	if (!*a)
		return ;
	front = *a;
	ft_lstdel_front(a);
	ft_lstadd_front(b, front);
	ft_putendl_fd("pb", 1);
}
