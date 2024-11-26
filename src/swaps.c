/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:53 by racasado          #+#    #+#             */
/*   Updated: 2024/11/26 14:10:35 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->count_a < 2)
		return ;
	tmp = stacks->stack_a->value;
	stacks->stack_a->value = stacks->stack_a->next->value;
	stacks->stack_a->next->value = tmp;
}

void	swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->count_b < 2)
		return ;
	tmp = stacks->stack_b->value;
	stacks->stack_b->value = stacks->stack_b->next->value;
	stacks->stack_b->next->value = tmp;
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
