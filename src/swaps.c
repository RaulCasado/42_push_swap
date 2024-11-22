/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:53 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:49:00 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int **stack_a, int **stack_b, int count_a, int count_b)
{
	int	tmp;

	(void)count_b;
	(void)stack_b;
	if (count_a < 2)
		return ;
	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
}

void	swap_b(int **stack_a, int **stack_b, int count_a, int count_b)
{
	int	tmp;

	(void)count_a;
	(void)stack_a;
	if (count_b < 2)
		return ;
	tmp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
}

void	swap_ab(int **stack_a, int **stack_b, int count_a, int count_b)
{
	swap_a(stack_a, stack_b, count_a, count_b);
	swap_b(stack_a, stack_b, count_a, count_b);
}
