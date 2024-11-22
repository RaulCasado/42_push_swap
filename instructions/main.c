/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:05:42 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:28:09 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("stack[%d] = %d\n", i, stack[i]);
		i++;
	}
}

int	ft_count_words(char *ptr, char delimiter)
{
	int	total_words;
	int	i;

	i = 0;
	total_words = 0;
	while (ptr[i])
	{
		if (ptr[i] != delimiter)
		{
			total_words++;
			while (ptr[i] && ptr[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (total_words);
}

int	is_already_ordered(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (stack[i + 1] < stack[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi_long(char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	is_int(char *str)
{
	long long	num;

	num = ft_atoi_long(str);
	if (!is_number(str))
		return (0);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	is_alredy_in_stack(int *stack, int count, int num)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	free_allocated_memory(char **splited, int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	free(stack);
}

#include <stdio.h>
#include <stdlib.h>

int	validate_arguments(int argc)
{
	if (argc < 2)
	{
		printf("Error no suficientes argumentos\n");
		return (0);
	}
	return (1);
}

int	count_numbers_in_splited(char **splited, int splited_count)
{
	int	total_numbers;
	int	j;

	total_numbers = 0;
	j = 0;
	while (j < splited_count)
	{
		if (!is_int(splited[j]) || !is_number(splited[j]))
		{
			printf("Error no es numero o no cabe en un int\n");
			free_allocated_memory(splited, NULL, 0);
			return (-1);
		}
		total_numbers++;
		j++;
	}
	return (total_numbers);
}

int	count_total_numbers(char **argvs)
{
	int		total_numbers;
	int		i;
	int		splited_count;
	char	**splited;
	int		result;

	total_numbers = 0;
	i = 1;
	while (argvs[i])
	{
		splited_count = ft_count_words(argvs[i], ' ');
		splited = ft_split(argvs[i], ' ');
		if (!splited)
			return (-1);
		result = count_numbers_in_splited(splited, splited_count);
		if (result == -1)
			return (-1);
		total_numbers += result;
		free_allocated_memory(splited, NULL, 0);
		i++;
	}
	return (total_numbers);
}

int	*initialize_stack(int total_numbers)
{
	int	*stack;

	stack = (int *)ft_calloc(total_numbers, sizeof(int));
	if (!stack)
	{
		printf("Error al asignar memoria\n");
		return (NULL);
	}
	return (stack);
}

int	process_splited_numbers(char **splited, int splited_count, int *stack,
		int *z)
{
	int	l;
	int	num;

	l = 0;
	while (l < splited_count)
	{
		num = ft_atoi(splited[l]);
		if (is_alredy_in_stack(stack, *z, num))
		{
			printf("Error ya esta en el stack\n");
			free_allocated_memory(splited, stack, l);
			return (0);
		}
		stack[(*z)++] = num;
		l++;
	}
	return (1);
}

int	fill_stack(char **argvs, int *stack)
{
	int		k;
	int		z;
	int		splited_count;
	char	**splited;

	k = 1;
	z = 0;
	while (argvs[k])
	{
		splited_count = ft_count_words(argvs[k], ' ');
		splited = ft_split(argvs[k], ' ');
		if (!splited)
			return (0);
		if (!process_splited_numbers(splited, splited_count, stack, &z))
			return (0);
		free_allocated_memory(splited, NULL, 0);
		k++;
	}
	return (1);
}

int	check_if_already_sorted(int *stack, int total_numbers)
{
	if (is_already_ordered(stack, total_numbers))
	{
		printf("Error ya estan ordenados\n");
		free(stack);
		return (0);
	}
	return (1);
}

void	process_stacks(int *stack, int total_numbers)
{
	int	*stack_b;

	stack_b = ft_calloc(0, sizeof(int));
	if (!stack_b)
	{
		free(stack);
		printf("Error al asignar memoria para stack_b\n");
		return ;
	}
	printf("stack before \n");
	print_stack(stack, total_numbers);
	free(stack);
	free(stack_b);
}

int	main(int argc, char **argvs)
{
	int	total_numbers;
	int	*stack;

	if (!validate_arguments(argc))
		return (1);
	total_numbers = count_total_numbers(argvs);
	if (total_numbers < 0)
		return (1);
	stack = initialize_stack(total_numbers);
	if (!stack)
		return (1);
	if (!fill_stack(argvs, stack))
		return (1);
	if (!check_if_already_sorted(stack, total_numbers))
		return (1);
	process_stacks(stack, total_numbers);
	return (0);
}
