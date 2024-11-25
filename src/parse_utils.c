/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:00:00 by racasado          #+#    #+#             */
/*   Updated: 2024/11/25 11:52:41 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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
			ft_printf("Error no es numero o no cabe en un int\n");
			free_allocated_memory(splited, NULL);
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
		free_allocated_memory(splited, NULL);
		i++;
	}
	return (total_numbers);
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
			ft_printf("Error ya esta en el stack\n");
			free_allocated_memory(splited, stack);
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
		free_allocated_memory(splited, NULL);
		k++;
	}
	return (1);
}
