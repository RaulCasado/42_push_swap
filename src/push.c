/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:09 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 12:37:20 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adjust_new_position(t_stacks *stacks)
{
	t_stack_node	*current;
	int				pos;

	current = stacks->stack_a;
	pos = 0;
	while (current)
	{
		current->position = pos;
		current = current->next;
		pos++;
	}
	current = stacks->stack_b;
	pos = 0;
	while (current)
	{
		current->position = pos;
		current = current->next;
		pos++;
	}
}

void	push_a(t_stacks *stacks)
{
	t_stack_node	*temp;

	if (stacks->count_b < 1)
		return ;
	temp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	temp->next = stacks->stack_a;
	stacks->stack_a = temp;
	adjust_new_position(stacks);
	stacks->count_a++;
	stacks->count_b--;
	ft_printf("pa\n");
}

void	push_b(t_stacks *stacks)
{
	t_stack_node	*temp;

	if (stacks->count_a < 1)
		return ;
	temp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	temp->next = stacks->stack_b;
	stacks->stack_b = temp;
	adjust_new_position(stacks);
	stacks->count_a--;
	stacks->count_b++;
	ft_printf("pb\n");
}
