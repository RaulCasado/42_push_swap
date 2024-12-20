/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 11:38:29 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_non_lis_to_b(t_stacks *stacks)
{
    int size = stacks->count_a;
    int i = 0;

    while (i < size)
    {
        if (stacks->stack_a->weight == 0)
            push_b(stacks);
        else
            rotate(stacks, 'a');
        i++;
    }
}

void perform_sort_lis(t_data *data)
{
    assign_indices(data->stacks, data->total_numbers);

    int lis_len;
    int *lis_indices = find_lis_indices(data->stacks, data->total_numbers, &lis_len);
    mark_lis_elements(data->stacks, lis_indices, lis_len, data->total_numbers);
    free(lis_indices);

    push_non_lis_to_b(data->stacks);
    insert_all_from_b(data->stacks);
}

void perform_sort(t_data *data)
{

    if (data->total_numbers == 2)
    {
        swap(data->stacks, 'a');
    }
    else if (data->total_numbers == 3)
    {
        sort_three(data->stacks);
    }
    else if (data->total_numbers <= 5)
    {
        sort_five(data->stacks);
    }
    else
    {
        perform_sort_lis(data);
    }
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
