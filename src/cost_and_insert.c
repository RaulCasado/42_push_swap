/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:54:46 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 11:56:58 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distance_to_top(int stack_count, int pos)
{
	int	half;

	half = stack_count / 2;
	if (pos <= half)
		return (pos);
	else
		return (pos - stack_count);
}

static int	get_stack_position_of_value(t_stack_node *stack, int count,
		int value)
{
	t_stack_node	*tmp;
	int				i;

	tmp = stack;
	i = 0;
	while (i < count)
	{
		if (tmp->position_no_change == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static t_cost	calculate_cost(t_stacks *stacks, int value)
{
	t_cost	cost;
	int		a_pos;
	int		b_pos;

	a_pos = find_insert_position(stacks, value);
	b_pos = get_stack_position_of_value(stacks->stack_b, stacks->count_b,
			value);
	cost.a_moves = distance_to_top(stacks->count_a, a_pos);
	cost.b_moves = distance_to_top(stacks->count_b, b_pos);
	cost.total_cost = abs(cost.a_moves) + abs(cost.b_moves);
	return (cost);
}

static int	find_best_element_to_insert(t_stacks *stacks)
{
	t_stack_node	*tmp;
	int				best_value;
	t_cost			best_cost;
	t_cost			current_cost;

	tmp = stacks->stack_b;
	best_value = tmp->position_no_change;
	best_cost = calculate_cost(stacks, best_value);
	tmp = tmp->next;
	while (tmp)
	{
		current_cost = calculate_cost(stacks, tmp->position_no_change);
		if (current_cost.total_cost < best_cost.total_cost)
		{
			best_cost = current_cost;
			best_value = tmp->position_no_change;
		}
		tmp = tmp->next;
	}
	return (best_value);
}

void	insert_all_from_b(t_stacks *stacks)
{
	int		best_val;
	t_cost	cost;

	while (stacks->count_b > 0)
	{
		best_val = find_best_element_to_insert(stacks);
		cost = calculate_cost(stacks, best_val);
		apply_rotations(stacks, cost.a_moves, cost.b_moves);
		push_a(stacks);
	}
	bring_min_to_top(stacks);
}
