/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:31 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:35:08 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	pa(t_list **a, t_list **b, int is_checker)
{
	t_list	*front;

	if (!*b)
		return ;
	front = *b;
	ft_lstdel_front(b);
	ft_lstadd_front(a, front);
	if (!is_checker)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **a, t_list **b, int is_checker)
{
	t_list	*front;

	if (!*a)
		return ;
	front = *a;
	ft_lstdel_front(a);
	ft_lstadd_front(b, front);
	if (!is_checker)
		ft_putendl_fd("pb", 1);
}
