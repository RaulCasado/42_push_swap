/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_from_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:28:20 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 12:30:04 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(t_stacks *stacks, int *min, int *max)
{
	t_stack_node	*cursor;
	int				i;

	cursor = stacks->stack_a;
	*min = cursor->position_no_change;
	*max = cursor->position_no_change;
	i = 0;
	while (i < stacks->count_a)
	{
		if (cursor->position_no_change < *min)
			*min = cursor->position_no_change;
		if (cursor->position_no_change > *max)
			*max = cursor->position_no_change;
		cursor = cursor->next;
		i++;
	}
}

static int	find_after_max(t_stacks *stacks, int max)
{
	t_stack_node	*cursor;
	int				i;

	cursor = stacks->stack_a;
	i = 0;
	while (i < stacks->count_a)
	{
		if (cursor->position_no_change == max)
			return ((i + 1) % stacks->count_a);
		cursor = cursor->next;
		i++;
	}
	return (0);
}

static int	find_best_pos(t_stacks *stacks, int val)
{
	t_stack_node	*cursor;
	int				i;
	int				best_pos;
	int				best_candidate;

	cursor = stacks->stack_a;
	best_pos = -1;
	best_candidate = INT_MAX;
	i = 0;
	while (i < stacks->count_a)
	{
		if (cursor->position_no_change > val
			&& cursor->position_no_change < best_candidate)
		{
			best_candidate = cursor->position_no_change;
			best_pos = i;
		}
		cursor = cursor->next;
		i++;
	}
	return (best_pos);
}

int	find_insert_position(t_stacks *stacks, int val)
{
	int	min;
	int	max;

	find_min_max(stacks, &min, &max);
	if (val < min || val > max)
		return (find_after_max(stacks, max));
	return (find_best_pos(stacks, val));
}
