#include "../include/push_swap.h"

t_stack	*init_stack(int size, int curr_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = (t_elem *)malloc(sizeof(t_elem) * size);
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