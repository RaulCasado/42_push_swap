/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:53 by racasado          #+#    #+#             */
/*   Updated: 2025/01/02 11:37:57 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->count_a < 2)
		return ;
	tmp = stacks->stack_a->value;
	stacks->stack_a->value = stacks->stack_a->next->value;
	stacks->stack_a->next->value = tmp;
}

static void	swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->count_b < 2)
		return ;
	tmp = stacks->stack_b->value;
	stacks->stack_b->value = stacks->stack_b->next->value;
	stacks->stack_b->next->value = tmp;
}

static void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}

void	swap(t_stacks *stacks, char stack_id)
{
	if (stack_id == 'a')
	{
		swap_a(stacks);
		ft_printf("sa\n");
	}
	else if (stack_id == 'b')
	{
		swap_b(stacks);
		ft_printf("sb\n");
	}
	else if (stack_id == 's')
	{
		swap_ab(stacks);
		ft_printf("ss\n");
	}
}
