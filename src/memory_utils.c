/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2025/01/09 18:47:02 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_allocated_memory(char **splited, int *stack)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	if (stack)
		free(stack);
}

int	*initialize_stack(int total_numbers)
{
	int	*stack;

	stack = (int *)ft_calloc(total_numbers, sizeof(int));
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (stack);
}
