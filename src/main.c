/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/25 12:28:26 by racasado         ###   ########.fr       */
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

int	main(int argc, char **argvs)
{
	int	total_numbers;
	int	*stack;

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
	print_stack(stack, total_numbers);
	free(stack);
	return (0);
}
