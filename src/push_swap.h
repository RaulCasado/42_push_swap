/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:00 by racasado          #+#    #+#             */
/*   Updated: 2025/01/07 19:05:31 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
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
int			setup_stacks(int argc, char **argvs, t_data *data);

/* Stack Operations */
int			is_already_ordered(int *stack, int count);
int			is_alredy_in_stack(int *stack, int count, int num);
int			*initialize_stack(int total_numbers);

/* Argument Validation */
int			validate_arguments(int argc, char **argvs);
int			is_number(char *str);
int			is_int(char *str);

/* Stack Parsing & Initialization */
int			count_total_numbers(char **argvs);
int			fill_stack(char **argvs, int *stack);

/* Memory Management */
void		free_allocated_memory(char **splited, int *stack);

/* Main Logic */
void		process_stacks(int *stack, int total_numbers);

/* Structs */
int			add_node_to_a(t_stacks *stacks, int value);
t_stacks	*initialize_stacks(void);
void		free_stacks(t_stacks *stacks);

/* Push */
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);

/* Auxiliaries for Swap, Rotate, Reverse Rotate */
void		swap(t_stacks *stacks, char stack_id);
void		rotate(t_stacks *stacks, char stack_id);
void		reverse_rotate(t_stacks *stacks, char stack_id);

/* Sorting Functions */
void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		update_target_positions(t_stacks *stacks);
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

/* lis helpers */
void		fill_arr(t_stacks *stacks, int *arr, int total);
void		init_lengths_prev(int *lengths, int *prev, int total);
int			calc_lis(int *arr, int *lengths, int *prev, int total);

/* rotations helper*/
void		apply_double_rotations(
				t_stacks *stacks, int *a_moves, int *b_moves);

#endif
