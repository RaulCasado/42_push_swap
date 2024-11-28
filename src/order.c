/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:28 by racasado          #+#    #+#             */
/*   Updated: 2024/11/28 13:07:02 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a->value;
	b = stacks->stack_a->next->value;
	c = stacks->stack_a->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		swap(stacks, 'a');
		reverse_rotate(stacks, 'a');
	}
	else if (a > b && b < c && a < c)
		swap(stacks, 'a');
	else if (a > b && b < c && a > c)
		rotate(stacks, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(stacks, 'a');
		rotate(stacks, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stacks, 'a');
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	min_node = stack;
	while (stack != NULL)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	sort_four(t_stacks *stacks)
{
	int	min;

	min = find_min(stacks->stack_a)->value;
	while (stacks->count_a > 3)
	{
		if (stacks->stack_a->value == min)
			push_b(stacks);
		else
			rotate(stacks, 'a');
	}
	sort_three(stacks);
	push_a(stacks);
}

void	sort_five(t_stacks *stacks)
{
	t_stack_node	*min;

	min = find_min(stacks->stack_a);
	while (stacks->count_a > 4)
	{
		if (stacks->stack_a->target_position == 0)
			push_b(stacks);
		else
		{
			if (min->position <= stacks->count_a / 2)
				rotate(stacks, 'a');
			else
				reverse_rotate(stacks, 'a');
		}
	}
	sort_four(stacks);
	push_a(stacks);
	while (stacks->stack_a->value != min->value)
		rotate(stacks, 'a');
}
