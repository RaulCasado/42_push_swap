/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2025/01/02 11:52:02 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_ordered(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (stack[i + 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_alredy_in_stack(int *stack, int count, int num)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}
