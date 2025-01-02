/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:03 by racasado          #+#    #+#             */
/*   Updated: 2025/01/02 11:42:21 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(t_stacks *stacks, int *arr, int total)
{
	t_stack_node	*tmp;
	int				i;

	tmp = stacks->stack_a;
	i = 0;
	while (i < total)
	{
		arr[i] = tmp->position_no_change;
		tmp = tmp->next;
		i++;
	}
}

void	init_lengths_prev(int *lengths, int *prev, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		lengths[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static void	update_lis(int *arr, int *lengths, int *prev, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[j] < arr[i] && lengths[j] + 1 > lengths[i])
		{
			lengths[i] = lengths[j] + 1;
			prev[i] = j;
		}
		j++;
	}
}

static int	find_lis_max(int *lengths, int total, int *max_pos)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	*max_pos = 0;
	while (i < total)
	{
		if (lengths[i] > max_len)
		{
			max_len = lengths[i];
			*max_pos = i;
		}
		i++;
	}
	return (max_len);
}

int	calc_lis(int *arr, int *lengths, int *prev, int total)
{
	int	i;
	int	max_pos;

	i = 0;
	while (i < total)
	{
		update_lis(arr, lengths, prev, i);
		i++;
	}
	find_lis_max(lengths, total, &max_pos);
	return (max_pos);
}
