/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:33:06 by dha               #+#    #+#             */
/*   Updated: 2022/02/13 14:36:54 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_call	init_call(void)
{
	t_call	call;

	call.pa = 0;
	call.pb = 0;
	call.ra = 0;
	call.rb = 0;
	call.rra = 0;
	call.rrb = 0;
	return (call);
}
