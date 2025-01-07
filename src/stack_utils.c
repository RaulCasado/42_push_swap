/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2025/01/07 20:19:50 by racasado         ###   ########.fr       */
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

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_space((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
