/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:38:00 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:44:02 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	com_execute(const char *com, t_list **a, t_list **b)
{
	if (ft_strncmp(com, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(com, "pb\n", 3) == 0)
		pb(a, b, 1);
	else if (ft_strncmp(com, "ra\n", 3) == 0)
		ra(a, 1);
	else if (ft_strncmp(com, "rb\n", 3) == 0)
		rb(b, 1);
	else if (ft_strncmp(com, "rr\n", 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(com, "rra\n", 4) == 0)
		rra(a, 1);
	else if (ft_strncmp(com, "rrb\n", 4) == 0)
		rrb(b, 1);
	else if (ft_strncmp(com, "rrr\n", 4) == 0)
		rrr(a, b, 1);
	else if (ft_strncmp(com, "sa\n", 3) == 0)
		sa(a, 1);
	else if (ft_strncmp(com, "sb\n", 3) == 0)
		sb(b, 1);
	else if (ft_strncmp(com, "ss\n", 3) == 0)
		ss(a, b, 1);
	else
		error_exit();
}

void	check(t_list **a, t_list **b)
{
	char	*com;

	com = get_next_line(0);
	while (com)
	{
		com_execute(com, a, b);
		com = get_next_line(0);
	}
	if (!is_sorted(*a, ft_lstsize(*a), 1) || *b != NULL)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	a = input(argc, argv);
	if (is_sorted(a, 0, 1))
		exit(EXIT_SUCCESS);
	check(&a, &b);
	exit(EXIT_SUCCESS);
}
