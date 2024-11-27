/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:40:13 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 13:06:17 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stacks *stacks, char stack_id)
{
	if (stack_id == 'a')
	{
		rotate_a(stacks);
		ft_printf("ra\n");
	}
	else if (stack_id == 'b')
	{
		rotate_b(stacks);
		ft_printf("rb\n");
	}
	else if (stack_id == 'r')
	{
		rotate_ab(stacks);
		ft_printf("rr\n");
	}
}

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

void	rotate_a(t_stacks *stacks)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stacks->count_a < 2)
		return ;
	first = stacks->stack_a;
	stacks->stack_a = first->next;
	last = stacks->stack_a;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	adjust_new_position(stacks);
}

void	rotate_b(t_stacks *stacks)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stacks->count_b < 2)
		return ;
	first = stacks->stack_b;
	stacks->stack_b = first->next;
	last = stacks->stack_b;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	adjust_new_position(stacks);
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
