/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:38:35 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 14:22:07 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_single_rotations(t_stacks *stacks, int a_moves, int b_moves)
{
	while (a_moves > 0)
	{
		rotate(stacks, 'a');
		a_moves--;
	}
	while (a_moves < 0)
	{
		reverse_rotate(stacks, 'a');
		a_moves++;
	}
	while (b_moves > 0)
	{
		rotate(stacks, 'b');
		b_moves--;
	}
	while (b_moves < 0)
	{
		reverse_rotate(stacks, 'b');
		b_moves++;
	}
}

void	apply_rotations(t_stacks *stacks, int a_moves, int b_moves)
{
	apply_double_rotations(stacks, &a_moves, &b_moves);
	apply_single_rotations(stacks, a_moves, b_moves);
}

static int	find_min_position(t_stacks *stacks)
{
	t_stack_node	*tmp;
	int				min_pos;
	int				min_val;
	int				i;

	tmp = stacks->stack_a;
	min_pos = 0;
	min_val = tmp->position_no_change;
	i = 0;
	while (i < stacks->count_a)
	{
		if (tmp->position_no_change < min_val)
		{
			min_val = tmp->position_no_change;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stacks *stacks, int min_pos)
{
	int	i;

	if (min_pos <= stacks->count_a / 2)
	{
		while (min_pos-- > 0)
			rotate(stacks, 'a');
	}
	else
	{
		i = stacks->count_a - min_pos;
		while (i-- > 0)
			reverse_rotate(stacks, 'a');
	}
}

void	bring_min_to_top(t_stacks *stacks)
{
	int	min_pos;

	min_pos = find_min_position(stacks);
	rotate_min_to_top(stacks, min_pos);
}
