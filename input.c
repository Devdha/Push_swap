/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:54:54 by dha               #+#    #+#             */
/*   Updated: 2022/02/08 13:38:05 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(const char *s, t_list **a)
{
	
}

void	str_input(const char *s, t_list **a)
{
	char	**split;
	int		i;

	split = ft_split(s, ' ');
	while (split[i] != NULL)
		check_input(split[i], a);
	
}

t_list	*input(int argc, char **argv)
{
	t_list	*a;
	int		i;
	
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			str_input(argv[i], &a);
		else
			check_input(argv[i], &a);
	}
}