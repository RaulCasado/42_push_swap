# include "push_swap.h"

static void find_min_max(t_stacks *stacks, int *min, int *max)
{
    t_stack_node *cursor;
    int i;

    cursor = stacks->stack_a;
    i = 0;

    *min = cursor->position_no_change;
    *max = cursor->position_no_change;
    while (i < stacks->count_a)
    {
        if (cursor->position_no_change < *min)
            *min = cursor->position_no_change;
        if (cursor->position_no_change > *max)
            *max = cursor->position_no_change;
        cursor = cursor->next;
        i++;
    }
}

static int find_after_max(t_stacks *stacks, int max)
{
    t_stack_node *cursor;
    int i;

    cursor = stacks->stack_a;
    i = 0;

    while (i < stacks->count_a)
    {
        if (cursor->position_no_change == max)
            return (i + 1) % stacks->count_a;
        cursor = cursor->next;
        i++;
    }
    return 0;
}

int find_best_pos(t_stacks *stacks, int val)
{
    t_stack_node *cursor = stacks->stack_a;
    int i = 0, best_pos = -1;
    int best_candidate = 2147483647;
    while (i < stacks->count_a)
    {
        if (cursor->position_no_change > val &&
            cursor->position_no_change < best_candidate)
        {
            best_candidate = cursor->position_no_change;
            best_pos = i;
        }
        cursor = cursor->next;
        i++;
    }
    return best_pos;
}

int find_insert_position(t_stacks *stacks, int val)
{
    int min, max;

    find_min_max(stacks, &min, &max);
    if (val < min || val > max)
        return find_after_max(stacks, max);
    return find_best_pos(stacks, val);
}