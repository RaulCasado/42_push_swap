/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:30:59 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_allocated_memory(char **splited, int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
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
		printf("Error al asignar memoria\n");
		return (NULL);
	}
	return (stack);
}
