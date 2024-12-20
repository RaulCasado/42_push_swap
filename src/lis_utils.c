/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:28:41 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 12:51:02 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_arr(t_stacks *stacks, int *arr, int total)
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

static void	init_lengths_prev(int *lengths, int *prev, int total)
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

static int	calc_lis(int *arr, int *lengths, int *prev, int total)
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

static void	rebuild_lis(int *lis_indices, int max_pos, int *prev, int lis_size)
{
	int	i;
	int	j;

	i = max_pos;
	j = lis_size - 1;
	while (i >= 0)
	{
		lis_indices[j--] = i;
		i = prev[i];
		if (i == -1)
			break ;
	}
}

static void	free_lis_resources(int *arr, int *lengths, int *prev)
{
	free(arr);
	free(lengths);
	free(prev);
}

static int	*allocate_resources(
	int total_numbers, int **arr, int **lengths, int **prev)
{
	*arr = malloc(sizeof(int) * total_numbers);
	*lengths = malloc(sizeof(int) * total_numbers);
	*prev = malloc(sizeof(int) * total_numbers);
	if (!*arr || !*lengths || !*prev)
	{
		free_lis_resources(*arr, *lengths, *prev);
		return (NULL);
	}
	return (*arr);
}

int	*find_lis_indices(t_stacks *stacks, int total_numbers, int *lis_size)
{
	int	*arr;
	int	*lengths;
	int	*prev;
	int	*lis_indices;
	int	max_pos;

	if (!allocate_resources(total_numbers, &arr, &lengths, &prev))
		return (NULL);
	fill_arr(stacks, arr, total_numbers);
	init_lengths_prev(lengths, prev, total_numbers);
	max_pos = calc_lis(arr, lengths, prev, total_numbers);
	*lis_size = lengths[max_pos];
	lis_indices = malloc(sizeof(int) * (*lis_size));
	if (!lis_indices)
	{
		free_lis_resources(arr, lengths, prev);
		return (NULL);
	}
	rebuild_lis(lis_indices, max_pos, prev, *lis_size);
	free_lis_resources(arr, lengths, prev);
	return (lis_indices);
}
