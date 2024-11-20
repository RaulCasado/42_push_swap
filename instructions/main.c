#include "../libft/libft.h"
#include <stdio.h>

void print_stack(int *stack, int count) {
    int i = 0;
    while (i < count) {
        printf("%d\n", stack[i]);
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

int is_already_ordered(int *stack, int count) {
    int i = 0;
    while (i < count - 1) {
        if (stack[i + 1] < stack[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_number(char *str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

long long ft_atoi_long(char *str) {
    long long res = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res * sign;
}

int is_int(char *str) {
    long long num = ft_atoi_long(str);
    if (!is_number(str))
        return 0;
    if (num > 2147483647 || num < -2147483648)
        return 0;
    return 1;
}

int is_alredy_in_stack(int *stack, int count, int num) {
    int i = 0;
    while (i < count) {
        if (stack[i] == num)
            return 1;
        i++;
    }
    return 0;
}

void free_allocated_memory(char **splited,int *stack,int count) {
    int i = 0;
    while (i < count) {
        free(splited[i]);
        i++;
    }
    free(splited);
    free(stack);
}

int main(int argc, char **argvs) {
    if (argc < 2) {
        printf("Error no suficientes argumentos\n");
        return 1;
    }
    int total_numbers = 0;
    int i = 1;
    while (argvs[i]) {
        int splited_count = ft_count_words(argvs[i], ' ');
        char **splited = ft_split(argvs[i], ' ');
        if (!splited)
            return 1;
        int j = 0;
        while (j < splited_count) {
            if (!is_int(splited[j]) || !is_number(splited[j])) {
                printf("Error no es numero o no cabe en un int\n");
                free_allocated_memory(splited, NULL, 0);
                return 1;
            }
            total_numbers++;
            j++;
        }
        i++;
    }

    int *stack = (int *)malloc(sizeof(int) * total_numbers);
    if (!stack)
        return 1;
    int k = 1;
    int l = 0;
    int z = 0;
    while (argvs[k]) {
        int splited_count = ft_count_words(argvs[k], ' ');
        char **splited = ft_split(argvs[k], ' ');
        if (!splited)
            return 1;
        l = 0;
        while (l < splited_count) {
            if (is_alredy_in_stack(stack, total_numbers, ft_atoi(splited[l]))) {
                printf("Error ya esta en el stack\n");
                free_allocated_memory(splited, stack, l);
                return 1;
            }
            stack[z] = ft_atoi(splited[l]);
            printf("stack[%d] = %d\n", z, stack[z]);
            l++;
            z++;
        }
        k++;
    }
    if (is_already_ordered(stack, total_numbers)) {
        printf("Error ya estan ordenados\n");
        free(stack);
        return 1;
    }
}
