/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:31 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:48:54 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(int **stack_a, int **stack_b, int count_a, int count_b)
{
	int	tmp;
	int	i;

	(void)count_b;
	(void)stack_b;
	if (count_a < 2)
		return ;
	tmp = (*stack_a)[count_a - 1];
	i = count_a - 1;
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = tmp;
}

void	reverse_rotate_b(int **stack_a, int **stack_b, int count_a, int count_b)
{
	int	tmp;
	int	i;

	(void)count_a;
	(void)stack_a;
	if (count_b < 2)
		return ;
	tmp = (*stack_b)[count_b - 1];
	i = count_b - 1;
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = tmp;
}

void	reverse_rotate_ab(int **stack_a, int **stack_b, int count_a,
		int count_b)
{
	reverse_rotate_a(stack_a, stack_b, count_a, count_b);
	reverse_rotate_b(stack_a, stack_b, count_a, count_b);
}
