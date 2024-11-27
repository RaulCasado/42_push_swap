/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:31 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 12:36:03 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stacks *stacks, char stack_id)
{
	if (stack_id == 'a')
	{
		reverse_rotate_a(stacks);
		ft_printf("rra\n");
	}
	else if (stack_id == 'b')
	{
		reverse_rotate_b(stacks);
		ft_printf("rrb\n");
	}
	else if (stack_id == 'r')
	{
		reverse_rotate_ab(stacks);
		ft_printf("rrr\n");
	}
}

void	reverse_rotate_a(t_stacks *stacks)
{
	t_stack_node	*last;
	t_stack_node	*second_last;
	t_stack_node	*current;
	int				pos;

	if (stacks->count_a < 2)
		return ;
	last = stacks->stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stacks->stack_a;
	stacks->stack_a = last;
	current = stacks->stack_a;
	pos = 0;
	while (current)
	{
		current->position = pos;
		current = current->next;
		pos++;
	}
}

void	reverse_rotate_b(t_stacks *stacks)
{
	t_stack_node	*last;
	t_stack_node	*second_last;
	t_stack_node	*current;
	int				pos;

	if (stacks->count_b < 2)
		return ;
	last = stacks->stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stacks->stack_b;
	stacks->stack_b = last;
	current = stacks->stack_b;
	pos = 0;
	while (current)
	{
		current->position = pos;
		current = current->next;
		pos++;
	}
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
