/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:17:06 by racasado          #+#    #+#             */
/*   Updated: 2024/11/28 13:34:30 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_already_sorted(int *stack, int total_numbers)
{
	if (is_already_ordered(stack, total_numbers))
	{
		ft_putstr_fd("Error", 2);
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

int	validate_and_initialize(int argc, char **argvs, t_data *data)
{
	if (!validate_arguments(argc))
		return (1);
	data->total_numbers = count_total_numbers(argvs);
	if (data->total_numbers < 0)
		return (1);
	data->stack = initialize_stack(data->total_numbers);
	if (!data->stack)
		return (1);
	if (!fill_stack(argvs, data->stack))
		return (1);
	if (!check_if_already_sorted(data->stack, data->total_numbers))
		return (1);
	return (0);
}

int	initialize_and_populate_stacks(t_data *data)
{
	data->stacks = initialize_stacks();
	if (!data->stacks)
		return (1);
	if (!populate_stack(data->stack, data->stacks, data->total_numbers))
	{
		free_stacks(data->stacks);
		return (1);
	}
	return (0);
}

int	setup_stacks(int argc, char **argvs, t_data *data)
{
	if (validate_and_initialize(argc, argvs, data))
		return (1);
	if (initialize_and_populate_stacks(data))
	{
		free(data->stack);
		return (1);
	}
	update_target_positions(data->stacks);
	return (0);
}
