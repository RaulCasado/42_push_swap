/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:19:58 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 14:25:09 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_double_rotations(t_stacks *stacks, int *a_moves, int *b_moves)
{
	while (*a_moves > 0 && *b_moves > 0)
	{
		rotate(stacks, 'r');
		(*a_moves)--;
		(*b_moves)--;
	}
	while (*a_moves < 0 && *b_moves < 0)
	{
		reverse_rotate(stacks, 'r');
		(*a_moves)++;
		(*b_moves)++;
	}
}
