/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:28 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 13:35:27 by racasado         ###   ########.fr       */
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
