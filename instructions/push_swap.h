/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/21 12:12:01 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap_a(int **stack_a, int **stack_b, int count_a ,int count_b);
void	swap_b(int **stack_a, int **stack_b, int count_a ,int count_b);
void	swap_ab(int **stack_a, int **stack_b, int count_a ,int count_b);
void	push_a(int **stack_a, int **stack_b, int count_a ,int count_b);
void	push_b(int **stack_a, int **stack_b, int count_a ,int count_b);
void	rotate_a(int **stack_a, int **stack_b, int count_a ,int count_b);
void	rotate_b(int **stack_a, int **stack_b, int count_a ,int count_b);
void	rotate_ab(int **stack_a, int **stack_b, int count_a ,int count_b);
void	reverse_rotate_a(int **stack_a, int **stack_b, int count_a ,int count_b);
void	reverse_rotate_b(int **stack_a, int **stack_b, int count_a ,int count_b);
void	reverse_rotate_ab(int **stack_a, int **stack_b, int count_a ,int count_b);

#endif