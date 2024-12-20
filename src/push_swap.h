/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:00 by racasado          #+#    #+#             */
/*   Updated: 2024/12/20 14:29:04 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					weight;
	int					position;
	int					target_position;
	int					position_no_change;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stacks
{
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
	int					count_a;
	int					count_b;
}						t_stacks;

typedef struct s_data
{
	int					total_numbers;
	int					*stack;
	t_stacks			*stacks;
}						t_data;

typedef struct s_cost
{
	int					a_moves;
	int					b_moves;
	int					total_cost;
}						t_cost;

/* Main functions */
int			check_if_already_sorted(int *stack, int total_numbers);
int			populate_stack(int *stack, t_stacks *stacks, int total_numbers);
int			validate_and_initialize(int argc, char **argvs, t_data *data);
int			initialize_and_populate_stacks(t_data *data);
int			setup_stacks(int argc, char **argvs, t_data *data);

/* Stack Operations */
void		print_stack(int *stack, int count);
int			is_already_ordered(int *stack, int count);
int			is_alredy_in_stack(int *stack, int count, int num);
int			*initialize_stack(int total_numbers);

/* Argument Validation */
int			validate_arguments(int argc);
int			is_number(char *str);
int			is_int(char *str);

/* Stack Parsing & Initialization */
int			ft_count_words(char *ptr, char delimiter);
int			count_numbers_in_splited(char **splited, int splited_count);
int			count_total_numbers(char **argvs);
int			process_splited_numbers(char **splited, int splited_count,
				int *stack, int *z);
int			fill_stack(char **argvs, int *stack);

/* Memory Management */
void		free_allocated_memory(char **splited, int *stack);

/* Main Logic */
int			check_if_already_sorted(int *stack, int total_numbers);
void		process_stacks(int *stack, int total_numbers);

/* Structs */
int			add_node_to_a(t_stacks *stacks, int value);
t_stacks	*initialize_stacks(void);
void		show_t_stacks(t_stacks *stacks);
void		free_stacks(t_stacks *stacks);

/* Swaps */
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_ab(t_stacks *stacks);

/* Push */
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);

/* Reverse Rotate */
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_ab(t_stacks *stacks);

/* Rotates */
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_ab(t_stacks *stacks);

/* Auxiliaries for Swap, Rotate, Reverse Rotate */
void		swap(t_stacks *stacks, char stack_id);
void		rotate(t_stacks *stacks, char stack_id);
void		reverse_rotate(t_stacks *stacks, char stack_id);

/* Sorting Functions */
void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		update_target_positions(t_stacks *stacks);
void		ft_sort_int_array(int *arr, int size);
int			binary_search(int *arr, int size, int value);
void		assign_indices(t_stacks *stacks, int total_numbers);

/* LIS Functions (from lis_utils, lis_mark, etc.) */
int			*find_lis_indices(t_stacks *stacks, int total_numbers,
				int *lis_size);
void		mark_lis_elements(t_stacks *stacks, int *lis_indices,
				int lis_len, int total_numbers);

/* Insert from B (position calculation) */
int			find_insert_position(t_stacks *stacks, int val);

/* Cost and insertion logic */
void		insert_all_from_b(t_stacks *stacks);

/* Rotations */
void		apply_rotations(t_stacks *stacks, int a_moves, int b_moves);
void		bring_min_to_top(t_stacks *stacks);

/* Additional sorting logic */
void		perform_sort_lis(t_data *data);
void		perform_sort(t_data *data);
void		clean_up(t_data *data);

/* lis helpers */
void		fill_arr(t_stacks *stacks, int *arr, int total);
void		init_lengths_prev(int *lengths, int *prev, int total);
void		update_lis(int *arr, int *lengths, int *prev, int i);
int			find_lis_max(int *lengths, int total, int *max_pos);
int			calc_lis(int *arr, int *lengths, int *prev, int total);

/* rotations helper*/
void		apply_double_rotations(
				t_stacks *stacks, int *a_moves, int *b_moves);

#endif
