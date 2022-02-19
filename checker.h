/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:04 by dha               #+#    #+#             */
/*   Updated: 2022/02/19 14:05:24 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "command.h"

t_list	*input(int argc, char **argv);

void	error_exit(void);
int		is_sorted(t_list *lst, int size, int ascending);
int		lst_value(t_list *lst);
int		lst_max(t_list *lst);

#endif