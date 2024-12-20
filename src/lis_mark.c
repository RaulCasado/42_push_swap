# include "push_swap.h"

static void init_mark_array(int *mark, int total)
{
    int i = 0;
    while (i < total)
    {
        mark[i] = 0;
        i++;
    }
}

static void apply_lis_marks(t_stacks *stacks, int *mark, int total)
{
    t_stack_node *tmp = stacks->stack_a;
    int i = 0;

    while (i < total)
    {
        tmp->weight = mark[i];
        tmp = tmp->next;
        i++;
    }
}

void mark_lis_elements(t_stacks *stacks, int *lis_indices, int lis_len, int total_numbers)
{
    int i = 0;
    int *mark = malloc(sizeof(int) * total_numbers);

    init_mark_array(mark, total_numbers);
    while (i < lis_len)
    {
        mark[lis_indices[i]] = 1;
        i++;
    }
    apply_lis_marks(stacks, mark, total_numbers);
    free(mark);
}