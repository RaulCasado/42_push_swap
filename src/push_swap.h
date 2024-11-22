/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:48:47 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

/* Stack Operations */
void	print_stack(int *stack, int count);
int		is_already_ordered(int *stack, int count);
int		is_alredy_in_stack(int *stack, int count, int num);
void	free_allocated_memory(char **splited, int *stack, int count);
int		*initialize_stack(int total_numbers);

/* Argument Validation */
int		validate_arguments(int argc);
int		is_number(char *str);
int		is_int(char *str);

/* Stack Parsing & Initialization */
int		ft_count_words(char *ptr, char delimiter);
int		count_numbers_in_splited(char **splited, int splited_count);
int		count_total_numbers(char **argvs);
int		process_splited_numbers(char **splited, int splited_count, int *stack,
			int *z);
int		fill_stack(char **argvs, int *stack);

/* Memory Management */
void	free_allocated_memory(char **splited, int *stack, int count);

/* Main Logic */
int		check_if_already_sorted(int *stack, int total_numbers);
void	process_stacks(int *stack, int total_numbers);

#endif
