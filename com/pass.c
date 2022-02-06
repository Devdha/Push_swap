/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:31 by dha               #+#    #+#             */
/*   Updated: 2022/02/05 21:52:42 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	ft_lstadd_back(a, ft_lstlast(*b));
	ft_lstdel_back(b);
}

void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	ft_lstadd_back(b, ft_lstlast(*a));
	ft_lstdel_back(a);
}
