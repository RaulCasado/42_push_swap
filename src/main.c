/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/26 14:10:51 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	check_if_already_sorted(int *stack, int total_numbers)
{
	if (is_already_ordered(stack, total_numbers))
	{
		ft_printf("Error ya estan ordenados\n");
		free(stack);
		return (0);
	}
	return (1);
}

int	populate_stack(int *stack, t_stacks *stacks, int total_numbers)
{
	int	i;

	i = 0;
	while (i < total_numbers)
	{
		if (!add_node_to_a(stacks, stack[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argvs)
{
	int			total_numbers;
	int			*stack;
	t_stacks	*stacks;

	if (!validate_arguments(argc))
		return (1);
	total_numbers = count_total_numbers(argvs);
	if (total_numbers < 0)
		return (1);
	stack = initialize_stack(total_numbers);
	if (!stack)
		return (1);
	if (!fill_stack(argvs, stack))
		return (1);
	if (!check_if_already_sorted(stack, total_numbers))
		return (1);
	stacks = initialize_stacks();
	if (!stacks)
	{
		free(stack);
		return (1);
	}
	if (!populate_stack(stack, stacks, total_numbers))
	{
		free(stack);
		free_stacks(stacks);
		return (1);
	}
	ft_printf("Stacks inicializados\n");
	show_t_stacks(stacks);
	ft_printf("Procesando stacks\n");
	reverse_rotate_a(stacks);
	ft_printf("Stacks procesados\n");
	show_t_stacks(stacks);
	free(stack);
	free_stacks(stacks);
	return (0);
}
