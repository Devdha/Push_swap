/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:39:17 by dha               #+#    #+#             */
/*   Updated: 2022/02/12 19:48:16 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "command.h"
# include <stdio.h>

typedef struct s_pair
{
	int	left;
	int	right;
}				t_pair;

t_list	*input(int argc, char **argv);
int		is_sorted(t_list *lst);
t_pair	get_pivot(t_list *lst);

#endif