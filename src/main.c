/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/28 13:19:36 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_sort(t_data *data)
{
	if (data->total_numbers == 2)
		swap(data->stacks, 'a');
	else if (data->total_numbers == 3)
		sort_three(data->stacks);
	else if (data->total_numbers == 4)
		sort_four(data->stacks);
	else if (data->total_numbers == 5)
		sort_five(data->stacks);
}

void	clean_up(t_data *data)
{
	free(data->stack);
	free_stacks(data->stacks);
}

int	main(int argc, char **argvs)
{
	t_data	data;

	if (setup_stacks(argc, argvs, &data))
		return (1);
	perform_sort(&data);
	clean_up(&data);
	return (0);
}
