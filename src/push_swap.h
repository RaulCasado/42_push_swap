/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/27 12:32:30 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					value;
	int					weight;
	int					position;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stacks
{
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
	int					count_a;
	int					count_b;
}						t_stacks;

/* Stack Operations */
void					print_stack(int *stack, int count);
int						is_already_ordered(int *stack, int count);
int						is_alredy_in_stack(int *stack, int count, int num);
int						*initialize_stack(int total_numbers);

/* Argument Validation */
int						validate_arguments(int argc);
int						is_number(char *str);
int						is_int(char *str);

/* Stack Parsing & Initialization */
int						ft_count_words(char *ptr, char delimiter);
int						count_numbers_in_splited(char **splited,
							int splited_count);
int						count_total_numbers(char **argvs);
int						process_splited_numbers(char **splited,
							int splited_count, int *stack, int *z);
int						fill_stack(char **argvs, int *stack);

/* Memory Management */
void					free_allocated_memory(char **splited, int *stack);
int						main_free(int *stack, int *stack_b);

/* Main Logic */
int						check_if_already_sorted(int *stack, int total_numbers);
void					process_stacks(int *stack, int total_numbers);

/* Structs */
int						add_node_to_a(t_stacks *stacks, int value);
t_stacks				*initialize_stacks(void);
void					show_t_stacks(t_stacks *stacks);
void					free_stacks(t_stacks *stacks);

/* Swaps */
void					swap_a(t_stacks *stacks);
void					swap_b(t_stacks *stacks);
void					swap_ab(t_stacks *stacks);

/* Push */
void					push_a(t_stacks *stacks);
void					push_b(t_stacks *stacks);
void					push_ab(t_stacks *stacks);

/* Reverse Rotate */
void					reverse_rotate_a(t_stacks *stacks);
void					reverse_rotate_b(t_stacks *stacks);
void					reverse_rotate_ab(t_stacks *stacks);

/* Rotates */
void					rotate_a(t_stacks *stacks);
void					rotate_b(t_stacks *stacks);
void					rotate_ab(t_stacks *stacks);

/* Auxiliaries for Swap, Rotate, Reverse Rotate */
void					swap(t_stacks *stacks, char stack_id);
void					rotate(t_stacks *stacks, char stack_id);
void					reverse_rotate(t_stacks *stacks, char stack_id);

/* Order */
void					sort_three(t_stacks *stacks);

#endif
