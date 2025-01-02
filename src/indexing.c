/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:32:08 by racasado          #+#    #+#             */
/*   Updated: 2025/01/02 11:40:58 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	binary_search(int *arr, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == value)
			return (mid);
		else if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_indices(t_stacks *stacks, int total_numbers)
{
	t_stack_node	*temp;
	int				*arr;
	int				i;
	int				idx;

	arr = malloc(sizeof(int) * total_numbers);
	if (!arr)
		return ;
	temp = stacks->stack_a;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	ft_sort_int_array(arr, total_numbers);
	temp = stacks->stack_a;
	while (temp)
	{
		idx = binary_search(arr, total_numbers, temp->value);
		temp->position_no_change = idx;
		temp->position = idx;
		temp = temp->next;
	}
	free(arr);
}
