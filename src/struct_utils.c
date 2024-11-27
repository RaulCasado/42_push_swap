/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:26:58 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 10:52:47 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(int value, int position)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->weight = -1;
	new_node->position = position;
	new_node->next = NULL;
	return (new_node);
}

t_stacks	*initialize_stacks(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->count_a = 0;
	stacks->count_b = 0;
	return (stacks);
}

void	show_t_stacks(t_stacks *stacks)
{
	t_stack_node	*node;

	node = stacks->stack_a;
	while (node)
	{
		ft_printf("stack_a[%d] = %d\n", node->position, node->value);
		node = node->next;
	}
	node = stacks->stack_b;
	while (node)
	{
		ft_printf("stack_b[%d] = %d\n", node->position, node->value);
		node = node->next;
	}
}

int	add_node_to_a(t_stacks *stacks, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = create_node(value, stacks->count_a);
	if (!new_node)
		return (0);
	if (!stacks->stack_a)
	{
		stacks->stack_a = new_node;
		stacks->count_a++;
		return (1);
	}
	last = stacks->stack_a;
	while (last->next)
		last = last->next;
	last->next = new_node;
	stacks->count_a++;
	return (1);
}

void	free_stacks(t_stacks *stacks)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

	node = stacks->stack_a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = stacks->stack_b;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stacks);
}
