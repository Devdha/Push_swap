/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:54:54 by dha               #+#    #+#             */
/*   Updated: 2022/02/18 23:39:41 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	check_dup(t_list *a, long long num)
{
	while (a)
	{
		if (lst_value(a) == num)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	check_input(const char *s, t_list **a)
{
	long long	num;
	int			*i;
	int			len;

	len = ft_strlen(s);
	len -= (s[0] == '-' || s[0] == '+');
	num = ft_atoll(s);
	if (!(ft_isnum(s) && len == ft_numlen(num)))
		error_exit();
	if (num > 2147483647 || num < -2147483648)
		error_exit();
	if (check_dup(*a, num))
		error_exit();
	i = (int *) malloc(sizeof(int));
	if (!i)
		exit(EXIT_FAILURE);
	*i = num;
	ft_lstadd_back(a, ft_lstnew(i));
}

static void	str_input(const char *s, t_list **a)
{
	char	**sp;
	int		i;

	i = 0;
	sp = ft_split(s, ' ');
	if (!sp)
		exit(EXIT_FAILURE);
	while (sp[i] != NULL)
	{
		check_input(sp[i], a);
		free(sp[i]);
		i++;
	}
	free(sp);
}

t_list	*input(int argc, char **argv)
{
	t_list	*a;
	int		i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			str_input(argv[i], &a);
		else
			check_input(argv[i], &a);
		i++;
	}
	return (a);
}
