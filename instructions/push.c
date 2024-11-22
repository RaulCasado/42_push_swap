/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:09 by racasado          #+#    #+#             */
/*   Updated: 2024/11/21 12:13:27 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	push_a(int **stack_a, int **stack_b, int count_a ,int count_b)
{
    int	i;

    if (count_b < 1)
        return ;
    i = count_a;
    while (i > 0)
    {
        (*stack_a)[i] = (*stack_a)[i - 1];
        i--;
    }
    (*stack_a)[0] = (*stack_b)[0];
    i = 0;
    while (i < count_b - 1)
    {
        (*stack_b)[i] = (*stack_b)[i + 1];
        i++;
    }
    (*stack_b)[i] = 0;
}

void	push_b(int **stack_a, int **stack_b, int count_a ,int count_b)
{
    int	i;

    if (count_a < 1)
        return ;
    i = count_b;
    while (i > 0)
    {
        (*stack_b)[i] = (*stack_b)[i - 1];
        i--;
    }
    (*stack_b)[0] = (*stack_a)[0];
    i = 0;
    while (i < count_a - 1)
    {
        (*stack_a)[i] = (*stack_a)[i + 1];
        i++;
    }
    (*stack_a)[i] = 0;
}

void	push_ab(int **stack_a, int **stack_b, int count_a ,int count_b)
{
    push_a(stack_a, stack_b, count_a, count_b);
    push_b(stack_a, stack_b, count_a, count_b);
}
