/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:01:32 by dha               #+#    #+#             */
/*   Updated: 2022/02/15 14:19:13 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *arr, int start, int end, int mid)
{
	int		*tmp;
	int		i;
	t_pair	idx;

	tmp = (int *) malloc(sizeof(int) * (end - start + 1));
	if (!tmp)
		exit(EXIT_FAILURE);
	i = start - 1;
	idx.left = start;
	idx.right = mid;
	while (++i < end)
	{
		if (idx.right == end)
			tmp[i - start] = arr[idx.left++];
		else if (idx.left == mid)
			tmp[i - start] = arr[idx.right++];
		else if (arr[idx.left] < arr[idx.right])
			tmp[i - start] = arr[idx.left++];
		else
			tmp[i - start] = arr[idx.right++];
	}
	i = start - 1;
	while (++i < end)
		arr[i] = tmp[i - start];
	free(tmp);
}

static void	merge_sort(int *arr, int start, int end)
{
	int	mid;

	if (start + 1 == end)
		return ;
	mid = (start + end) / 2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid, end);
	merge(arr, start, end, mid);
}

t_pair	get_pivot(t_list *lst, int size)
{
	t_pair	pivot;
	int		*arr;
	int		i;

	arr = (int *) malloc(sizeof(int) * size);
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	while (lst && i < size)
	{
		arr[i++] = lst_value(lst);
		lst = lst->next;
	}
	merge_sort(arr, 0, size);
	pivot.left = arr[size / 3];
	pivot.right = arr[size * 2 / 3];
	free(arr);
	return (pivot);
}
