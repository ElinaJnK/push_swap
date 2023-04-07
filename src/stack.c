#include "../include/push_swap.h"

t_stack	*init_stack(int size, int curr_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = (int *)malloc(sizeof(int) * size);
	if (!stack->tab)
		return (NULL);
	stack->size = size;
	stack->curr_size = curr_size;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->tab);
	free(stack);
}

int	get_i(int *sorted_tab, int value)
{
	int	i;

	i = 0;
	while (sorted_tab[i] != value)
		i++;
	return (i);
}

void	update_stack(int *sorted_tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->tab[i] = get_i(sorted_tab, stack->tab[i]);
		i++;
	}
}

void	till_not_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->tab[i] != 0)
		i++;
	if (i < a->size / 2)
		while (check_sorted(a) == EXIT_FAILURE)
			do_move(a, b, "ra");
	else
		while (check_sorted(a) == EXIT_FAILURE)
			do_move(a, b, "rra");
}
