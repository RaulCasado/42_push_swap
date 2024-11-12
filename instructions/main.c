#include "../libft/libft.h"
#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2) {
    if (!s1 || !s2)
        return 0;
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

void print_stack(int *stack, int count) {
    int i = 0;
    while (i < count) {
        printf("%d\n", stack[i]);
        i++;
    }
}
int has_consecutive_spaces(char *str) {
    while (*str) {
        if (*str == ' ' && *(str + 1) == ' ')
            return 1;
        str++;
    }
    return 0;
}

int contains_repeated(char **argvs) {
    int i = 0;
    int j;
    while (argvs[i]) {
        j = i + 1;
        while (argvs[j]) {
            if (ft_strcmp(argvs[i], argvs[j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
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

int is_valid_number(char *str) {
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

void free_stack(int *stack_a) {
    free(stack_a);
}

int main(int argc, char **argvs) {
    int *stack_a;
    char **args;
    int count = argc - 1;

    if (argc < 2) {
        ft_putstr_fd("Error: not enough arguments\n", 2);
        return 1;
    }

    if (argc == 2) {
        if (has_consecutive_spaces(argvs[1])) {
            ft_putstr_fd("Error: consecutive spaces found\n", 2);
            return 1;
        }
        args = ft_split(argvs[1], ' ');
        if (!args) {
            ft_putstr_fd("Error: memory allocation failed\n", 2);
            return 1;
        }
        count = 0;
        while (args[count])
            count++;
    } else {
        args = argvs + 1;
    }

    stack_a = malloc(count * sizeof(int));
    if (!stack_a) {
        ft_putstr_fd("Error: memory allocation failed\n", 2);
        if (argc == 2) free(args);
        return 1;
    }

    if (contains_repeated(args)) {
        ft_putstr_fd("Error: duplicate arguments found\n", 2);
        free_stack(stack_a);
        if (argc == 2) free(args);
        return 1;
    }

    int i = 0;
    while (i < count) {
        if (!is_valid_number(args[i])) {
            ft_putstr_fd("Error: invalid argument\n", 2);
            free_stack(stack_a);
            if (argc == 2) free(args);
            return 1;
        }
        if (is_alredy_in_stack(stack_a, i, ft_atoi(args[i]))) {
            ft_putstr_fd("Error: duplicate arguments found\n", 2);
            free_stack(stack_a);
            if (argc == 2) free(args);
            return 1;
        }
        stack_a[i] = ft_atoi(args[i]);
        i++;
    }

    if (argc == 2) {
        int j = 0;
        while (args[j]) {
            free(args[j]);
            j++;
        }
        free(args);
    }
    print_stack(stack_a, count);
    free_stack(stack_a);
    return 0;
}
