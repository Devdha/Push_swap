/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:55:06 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 16:52:59 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst, int size, int ascending)
{
	int	i;

	i = 0;
	if (size == 0)
		size = ft_lstsize(lst);
	while (lst->next && i < size)
	{
		{
			if (ascending && lst_value(lst) > lst_value(lst->next))
				return (0);
			else if (!ascending && lst_value(lst) < lst_value(lst->next))
				return (0);
			lst = lst->next;
			i++;
		}
	}
	return (1);
}

int	lst_value(t_list *lst)
{
	return (*(int *) lst->content);
}

int	lst_max(t_list *lst)
{
	int	max;

	max = 0x80000000;
	while (lst)
	{
		if (lst_value(lst) > max)
			max = lst_value(lst);
		lst = lst->next;
	}
	return (max);
}
