/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:07 by racasado          #+#    #+#             */
/*   Updated: 2024/11/28 12:06:50 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_position(t_stacks *stacks, int value)
{
	int				target_position;
	t_stack_node	*current;

	target_position = 0;
	current = stacks->stack_a;
	while (current != NULL)
	{
		if (current->value < value)
		{
			target_position++;
		}
		current = current->next;
	}
	return (target_position);
}

void	update_target_positions(t_stacks *stacks)
{
	t_stack_node	*current;

	current = stacks->stack_a;
	while (current != NULL)
	{
		current->target_position = find_target_position(stacks, current->value);
		current = current->next;
	}
}
