/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:41:46 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 20:27:12 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	v(void *a)
{
	printf("%d\n", *(int *) a);
}

void	push_swap(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 3)
		three_sort(a);
	else if (size == 5)
		five_sort(a, b);
	else
		a_to_b(ft_lstsize(*a), a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_pair	c;

	b = NULL;
	if (argc < 2)
		return (0);
	a = input(argc, argv);
	if (is_sorted(a, 0, 1))
		return (0);
	push_swap(&a, &b);
	//ft_lstiter(a, v);
	//printf("--------\n");
	//ft_lstiter(b, v);
}
